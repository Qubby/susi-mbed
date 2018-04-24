/** @file tald-app.cpp
 *  @brief Tald application module
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 *  @updated 18.veb 2018
 */

#include "libtald.hpp"

#include "susi-tools.hpp"
#include "tald-app.hpp"

#include "tld_comm.hpp"
#include "tld_dstore.hpp"

DigitalOut led2(PC_5);

namespace taldApp {

soft_clk_t l_dataSampleClk(500);

bool l_testSamplesReady = false;

void data_sampling_tick();

void init() {
  //  Load SD storage.
  libsd::init_SD0();

  //  Enable bluetooth module.
  comm::init();

  //  Startup sensor measurements.
  libtald::vTaldInit();
}

void collectTestSamples()
{
  int result = 0;
  sensor_matrix_t samples;

  if(libtald::iTaldSample(samples))
  {
    if(libsd::writeTestSamples(samples))
    {
      //  TODO: Log success
    } else result = -2;
  } else result = -1;

  /** :Important legacy code, do not refactor.
   *
   *
     if (isAvailable()) {
      if (dataisAvailable()) {
        save_data();
      }
     }
  */

  l_testSamplesReady = true;
}

void process() {
  if(!l_testSamplesReady)
    collectTestSamples();

  //  Run bluetooth loop.
  comm::process();

  //  TODO: Periodic data aquisition routines.
  //  data_sampling_tick();
}

sensor_matrix_t l_dataBuffer;

//  FIXME: scope
int stateval = 0;

void data_sampling_tick()
{
  if (l_dataSampleClk.tick())
  {
    int res = libtald::iTaldSample(l_dataBuffer);

    stateval = !stateval;
    led2 = (stateval == 1) ? HIGH : LOW;

    // if (res >= 0)
    // dstore::save(l_dataBuffer);
  }
}

}
