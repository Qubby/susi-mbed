
#ifndef LIBSD_H
#define LIBSD_H

#include "susi-env.hpp"

namespace libsd {

int init_SD0();

int writeTestSamples(const libtald::sensor_matrix_t& sensorData);

}

#endif
