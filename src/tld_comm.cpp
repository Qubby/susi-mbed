/** @file tldcomm.cpp
 *  @brief Tald communication module implementation
 *
 *  @author Margo Martis
 *  @date 30. April 2016
 *  @version 0.1
 */

#include "tld_comm.hpp"

// using namespace libtald::sense;

namespace libtald {
namespace comm {

DigitalInOut BLE_RDY(PB_6);
DigitalInOut BLE_REQ(PA_15);

BLEPeripheral blePeripheral = BLEPeripheral(&BLE_REQ, &BLE_RDY, NULL);

BLEService uartService = BLEService("713d0000503e4c75ba943148f18d941e");

BLECharacteristic txCharacteristic =
    BLECharacteristic("713d0002503e4c75ba943148f18d941e", BLENotify, 20);
BLECharacteristic rxCharacteristic =
    BLECharacteristic("713d0003503e4c75ba943148f18d941e", BLEWrite, 20);

comm_state_e g_send_st;
comm_ctx_t g_ctx;

bool BLEisAvailable = false;

void debug() {
  if (g_ctx.data[0][0] > 128) {
    // led = 0;
  } else {
    // led = 1;
  }
}

bool isAvailable() { return BLEisAvailable; }

/*void recv() {
  if (rxCharacteristic.written()) {
    unsigned char rxlen = rxCharacteristic.valueLength();
    const unsigned char *val = rxCharacteristic.value();
    serial.printf("didCharacteristicWritten, Length: %d\r\n", rxlen);
    unsigned char i = 0;

    while (i < rxlen) {
      serial.printf("%d, ", val[i++]);
    }
    serial.printf("\r\n");
  }
}*/

int create_data_post() {
  // FIXME: load data from storage instead
  // if(read_sensor_matrix(g_ctx.data) < 0) return -1;

  debug();

  g_ctx.psize = TLD_SMX_Y;  // Packet length
  g_ctx.pcount = TLD_SMX_X; // Packet count
  g_ctx.pix = 0;

  iTaldSample(g_ctx.data);

  return 0;
}

int process_data_post() {
  blePeripheral.poll();
  while (blePeripheral._nRF8001._aciState.data_credit_available > 0) {
    if (g_ctx.pix < g_ctx.pcount) {
      txCharacteristic.setValue(g_ctx.data[g_ctx.pix], g_ctx.psize);
      g_ctx.pix++;
    } else
      return 1;

    blePeripheral.poll();
  }

  if (g_ctx.pix >= g_ctx.pcount)
    return 1;

  return 0;
}

void send() {
  int res;
  switch (g_send_st) {
  case ECS_IDLE:
    res = create_data_post();
    if (res >= 0)
      g_send_st = ECS_SENDING;
    break;
  case ECS_SENDING:
    res = process_data_post();
    if (res != 0)
      g_send_st = ECS_IDLE;
    break;

  default:
    break;
  }
}

void init() {
  DigitalOut RESET_BLE(PD_2);
  RESET_BLE = 0;
  wait_us(0.5);
  RESET_BLE = 1;

  blePeripheral.setLocalName("NRF8001");
  blePeripheral.setAdvertisedServiceUuid(uartService.uuid());

  blePeripheral.addAttribute(uartService);
  blePeripheral.addAttribute(rxCharacteristic);
  blePeripheral.addAttribute(txCharacteristic);

  blePeripheral.begin();
  g_send_st = ECS_IDLE;

  BLEisAvailable = false;
}

void process() {
  BLECentral central = blePeripheral.central();
  if (central) {
    if (central.connected()) {
      send();
    }
  }
}
}
}
