/** @file libtald.hpp
 *  @brief Tald module implementation
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 *  @updated 18.veb 2018
 */

#ifndef LIBTALD_H
#define LIBTALD_H

#include "app.h"
// CD demux
#define TLD_ADDR_OUT PortA
#define TLD_ADDR_OMASK 0xF0

// ADG mux
#define TLD_ADDR_IN PortC
#define TLD_ADDR_IMASK 0x0F

#define TLD_DATA_EN PA_1 // CD DEMUX)
#define TLD_DATA_IN PA_0 // ADG (MUX)

#define TLD_SMX_X 16
#define TLD_SMX_Y 16
#define TLD_SMX_L 256

namespace libtald {

// abcd -> dcba
inline uint8_t addr_MUX(uint8_t ix) {
  uint8_t mask = 0;
  while (ix != 0) {
    mask <<= 1;
    mask |= (ix & 1);
    ix >>= 1;
  }
  return mask;
}

// mask = ((ix << 2) & (0b1100)) | ((ix >> 2) & 0b0011);
// mask = (((mask & 0b1) << 1) | ((mask & 0b10) >> 1) | ((mask & 0b100) << 1) |
//         ((mask & 0b1000) >> 1));
// bits: 0 1 2 3. 9 == 0b1001, pin_mask == 0b0110
// pmap: PA6, PA7, PA4, PA5
inline uint8_t addr_DeMUX(uint8_t ix) {
  uint8_t mask = ((ix >> 2) & 0b0011) | ((ix << 2) & 0b1100);

  return mask << 4;
}

typedef uint8_t sensor_matrix_t[16][16];

struct vec2u_t {
  unsigned int x, y;
};

struct bus_out_t {
  DigitalOut enableOut;
  PortOut port;
  uint8_t x;
};

struct bus_in_t {
  AnalogIn dataIn;
  PortOut port;
  uint8_t y;
};

struct tald_t {
  //  DeMUX Address bus.
  bus_out_t busOut;

  // MUX Address bus.
  bus_in_t busIn;

  void selectRow(unsigned int _x) {
    // busOut.enableOut = 0;

    _x = addr_DeMUX(_x);
    if (_x < 16)
      return;

    busOut.port = _x;
    busOut.x = _x;

    busOut.enableOut = 1;
  }

  void selectColumn(unsigned int _y) {
    _y = addr_MUX(_y);
    if (_y < 16)
      return;

    busIn.port = _y;
    busIn.y = _y;
  }

  void select(unsigned int x, unsigned int y) {
    selectRow(x);
    selectColumn(y);
  }

  uint16_t read(unsigned int x, unsigned int y) {
    select(x, y);
    return busIn.dataIn.read_u16();
  }
};

void vTaldInit();
int iTaldSample(sensor_matrix_t &);
}
#endif
