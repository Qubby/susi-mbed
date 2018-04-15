/** @main.cpp
 *  @brief Tald application
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 */
#include "app.h"
#include "tald-app.hpp"
#include <stdint.h>

Serial serial(USBTX, USBRX); // TX,RX

SPI spi(PB_5, PB_4, PB_3);

// DigitalOut l_inputCtl_EN0(PC_0);
// DigitalOut l_inputCtl_EN1(PC_1);

void millisStart(void) { SysTick_Config(SystemCoreClock / 1000); }

int main() {
  millisStart();
  serial.baud(115200);
  taldApp::init();
  while (1) {
    taldApp::process();
  }
}

volatile unsigned long _millis;
extern "C" void SysTick_Handler(void) { _millis++; }
unsigned long millis(void) { return _millis; }
