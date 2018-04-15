/** @file tld.cpp
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
  for (size_t x = 1; x < 2; x++) {   // Rida TLD_SMX_X
    for (size_t y = 1; y < 2; y++) { // Veerg TLD_SMX_Y
      // smx[x][y] = (uint8_t)y;                // debug
      uint16_t sample_u16 = gTald.read(x, y);

      uint8_t sample_u8 = (sample_u16 * 255.0) / 4095.0; // 1-4095

      smx[x][y] = sample_u8;

      // smx[x][y] = (uint8_t)gTald.read(x, y) << 8;
    }
  }
  return 0;
}
}
