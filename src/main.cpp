
#include "app.h"
#include "tald-app.hpp"
#include <stdint.h>

Serial serial(USBTX, USBRX); // TX,RX

SPI spi(PB_5, PB_4, PB_3);

DigitalOut led(PC_4);

void millisStart(void) { SysTick_Config(SystemCoreClock / 1000); }

int main() {
  millisStart();
  serial.baud(115200);
  led = 1;

  taldApp::init();

  while (1) {
    taldApp::process();
  }
}

volatile unsigned long _millis;
extern "C" void SysTick_Handler(void) { _millis++; }
unsigned long millis(void) { return _millis; }
