/** @file libtld.cpp
 *  @brief Tald module implementation
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 */

#include "libtald.hpp"

namespace libtald {

tald_t gTald({{TLD_DATA_EN, {TLD_ADDR_OUT, TLD_ADDR_OMASK}, 0},
              {TLD_DATA_IN, {TLD_ADDR_IN, TLD_ADDR_IMASK}, 0}});

void vTaldInit() {}

int iTaldSample(sensor_matrix_t &smx) {
  for (size_t x = 2; x < 3; x++) {
    for (size_t y = 2; y < 3; y++) {
      uint16_t u16 = gTald.read(x, y);
      uint8_t u8 = (u16 * 255.0 / 4095.0);
      smx[x][y] = (uint8_t)u8;
      // smx[x][y] = (uint8_t)(gTald.read(x, y) >> 8);
    }
  }
  return 0;
}
}
