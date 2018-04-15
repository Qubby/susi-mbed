/** @file tldsens.cpp
 *  @Tald data store module implementation
 *
 *  @author Margo Martis
 *  @date 03. May 2016
 *  @version 0.1
 */

#include <string>

#include "base64.h"

#include "mbed.h"
//#include "SDFileSystem/SDFileSystem.h"

#include "tld_dstore.hpp"

namespace libtald {
namespace dstore {

// SDFileSystem sd(PB_15, PB_14, PB_13, PB_12, "sd"); //Mosi,Miso,Clk,CS

bool data_avail_flag = false;
bool store_avail_flag = false;

void init() {
  FILE *fp = fopen("/sd/Connected.txt", "w");

  if (fp != NULL) {
    store_avail_flag = true;
    // led2 = 1;
    fclose(fp);
  }
}

void process() {}

void MakeHeader() {
  header_t data;
  data.odbegin = 0;
  data.ndstart = 0;
  data.ndend = 0;
}
/*string Data_to_String(data_t data)
{
  std::string packet = "";
  packet += std::to_string(data.timestamp);
  for (int x = 0; x < 8; x++)
  {
    packet += "\r\n";
    for (int y = 0; y < 8; y++)
    {
             packet += std::to_string(data.data[x][y])
             packet += " ";
    }
  }
  packet += "\r\n";
  return packet;
}
*/

int save_data(data_t data) {
  const char *fp = "/sd/mydir/sdtest.txt";
  FILE *fd = NULL;

  fd = fopen(fp, "w");
  if (fd == NULL) {
    mkdir("/sd/mydir", 0777);
  }

  fd = fopen(fp, "w");
  if (fd == NULL)
    return -1;

  header_t hdata;
  hdata.odbegin, hdata.ndstart, hdata.ndend = 0;
  fprintf(fd, "odbegin=%lu,ndstart=%lu,ndend=%lu;\n", hdata.odbegin,
          hdata.ndstart, hdata.ndend);

  if (fd != NULL)
    fclose(fd);
  return 0;
}

int load_data(data_t data) {
  // uint32_t LoadTime;
  // FILE *fp = fopen("/sd/mydir/sdtest.txt", "r");
  return -1;
}

uint32_t get_current_timestamp() { return 0; }

bool isAvailable() { return store_avail_flag; }
bool dataAvailable() { return data_avail_flag; }
}
}
