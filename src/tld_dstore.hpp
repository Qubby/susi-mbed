/** @file tlddstore.cpp
 *  @brief Tald data store module
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 */

#ifndef TLD_DSTORE_H
#define TLD_DSTORE_H

#include "app.h"
#include "libtald.hpp"

namespace libtald {
namespace dstore {

struct dstore_data_t {
  uint32_t timestamp;
  sensor_matrix_t data;
};

struct header_t {
  uint32_t timestamp;
  uint32_t odbegin;
  uint32_t ndstart;
  uint32_t ndend;
};

void init();
void process();

// int save_data(data_t);
// int load_data(data_t);

bool dataAvailable();
bool isAvailable();

int writeTestSamples(uint8_t*, size_t);

uint32_t get_current_timestamp();
}
}

#endif
