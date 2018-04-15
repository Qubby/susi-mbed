/** @file tald-app.cpp
 *  @brief Tald application module
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 *  @updated 18.veb 2018
 */

#include "libtald.hpp"
#include "soft_clock.hpp"
#include "tald-app.hpp"
#include "tld_comm.hpp"
#include "tld_dstore.hpp"

DigitalOut led2(PC_5);

namespace taldApp {

soft_clk_t l_dataSampleClk(500);
// soft_clk_t l_dataSubmissionClk(1000);

sensor_matrix_t l_dataBuffer;

void data_sampling_tick();
void data_submission_tick();

void init() {
  dstore::init();
  comm::init();

  libtald::vTaldInit();
}

void process() {
  dstore::process();
  comm::process();

  data_sampling_tick();
  // data_submission_tick();
}

int stateval = 0;

void data_sampling_tick() {
  if (l_dataSampleClk.tick()) {
    int res = libtald::iTaldSample(l_dataBuffer);

    stateval = !stateval;
    led2 = (stateval == 1) ? HIGH : LOW;

    // if (res >= 0)
    // dstore::save(l_dataBuffer);
  }
}

// void data_submission_tick() {
//   if (l_dataSubmissionClk.tick()) {
//     if (dstore::isAvailable) {
//     }
//   }
// }

} /* susi */
