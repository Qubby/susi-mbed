/** @file tldsens.hpp
 *  @brief Tald sensor module
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 *  @updated 18.veb 2018
 */

#ifndef LIBTALD_H
#define LIBTALD_H

#include "app.h"
// mux
#define TLD_ADDR_OUT PortA
#define TLD_ADDR_OMASK 0xF0

// demux(CD)
#define TLD_ADDR_IN PortC
#define TLD_ADDR_IMASK 0x0F

#define TLD_DATA_EN PA_0 // CD DEMUX)
#define TLD_DATA_IN PA_1 // ADG (MUX)

#define TLD_SMX_X 16
#define TLD_SMX_Y 16
#define TLD_SMX_L 256

namespace libtald {

inline uint8_t tald_addr_obits(unsigned int n) {
  // n - > 5 4 7 6 => 7 6 5 4
  uint8_t r = ((n & (1 << 0)) << 2);
  r |= ((n & (1 << 1)) << 2);
  r |= ((n & (1 << 2)) >> 2);
  r |= ((n & (1 << 3)) >> 2);

  return r << 4;
}

inline uint8_t tald_addr_ibits(unsigned int n) {
  // n -> 0 1 2 3 -> 3 2 1 0
  uint8_t r = ((n & (1 << 0)) << 3);
  r = ((n & (1 << 1)) << 1);
  r = ((n & (1 << 2)) >> 1);
  r = ((n & (1 << 3)) >> 3);

  return r;
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
  bus_out_t busOut;
  bus_in_t busIn;

  void selectRow(unsigned int _x) {
    busOut.enableOut = 0;

    _x = tald_addr_obits(_x);
    if (_x >= 16)
      return;

    busOut.port = _x;
    busOut.x = _x;

    busOut.enableOut = 1;
  }

  void selectColumn(unsigned int _y) {
    _y = tald_addr_ibits(_y);
    if (_y >= 16)
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
