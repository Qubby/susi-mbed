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
  uint32_t u16, ix;

  for (size_t x = 0; x < 6; x++) {
    for (size_t y = 0; y < 6; y++) {
      u16 = gTald.read(x, y);

      ix = y * 2;
      smx[x][ix] = u16 & 0xFF;
      smx[x][ix + 1] = (u16 >> 8) & 0xFF;
      // smx[x][y] = (uint8_t)(gTald.read(x, y) >> 8);
    }
  }
  return 0;
}
}
