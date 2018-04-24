
#include "SDFileSystem.h"

#include "libsd.hpp"

struct sd_fs_pinout_t { PinName MOSI, MISO, CLK, CS; };

// Static global SPI interface pinout.
const sd_fs_pinout_t SPI0 = { PB_15, PB_14, PB_13, PB_12 };

namespace libsd {

SDFileSystem gSD0(SPI0.MOSI, SPI0.MISO, SPI0.CLK, SPI0.CS, "SD0");

bool l_initFlag = false;

int writeTestSamples(const libtald::sensor_matrix_t& sensorData) {
  if(!l_initFlag) return -1;

  FILE *fp = fopen("/sd/susi/test-samples.csv", "w");

  //  gSD0.write("/test-samples.csv", pData, length);
  for(int i = 0, j = 0; i < 16; ++i)
  {
    fprintf(fp, "%u,", sensorData[i][j]);

    if(i == 15)
    {
      fprintf(fp, "\n");

      j++;
      i = 0;

      if(j == 16) break;
    }
  }

  fprintf(fp, "\n");
  fclose(fp);

  return 0;
}

/**


*/
int init_SD0() {
  //  Initialize SD connection.

  int result = 0; //  FIXME:  = gSD0.begin();

  if(!result) {
    //  TODO: Log error.
  }

  l_initFlag = true;

  return 0;
}

}
