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

// #define TLD_DATA_IN PA_0 // ADG (MUX)
// #define TLD_ADDR_IN1 PortC
// #define TLD_ADDR_IMASK1 0x0F

Serial serial(USBTX, USBRX); // TX,RX

SPI spi(PB_5, PB_4, PB_3);

// PortOut demux_out(TLD_ADDR_IN1, TLD_ADDR_IMASK1);

void millisStart(void) { SysTick_Config(SystemCoreClock / 1000); }

int main() {
  millisStart();
  serial.baud(115200);
  taldApp::init();
  // demux_out = 0x0F;

  while (1) {
    taldApp::process();
  }
}

volatile unsigned long _millis;
extern "C" void SysTick_Handler(void) { _millis++; }
unsigned long millis(void) { return _millis; }
