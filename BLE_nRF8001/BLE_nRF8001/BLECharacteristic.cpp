#include "Arduino.h"
#include "BLECharacteristic.h"

BLECharacteristic::BLECharacteristic(const char* uuid, unsigned char properties, unsigned char valueSize, bool fixedLength) :
  BLEAttribute(uuid, BLETypeCharacteristic),
  _properties(properties),
  _valueSize(min(valueSize, BLE_ATTRIBUTE_MAX_VALUE_LENGTH)),
  _valueLength(0),
  _fixedLength(fixedLength),
  _written(false),
  _subscribed(false),
  _listener(NULL)
{
  memset(this->_eventHandlers, 0x00, sizeof(this->_eventHandlers));

  _value = (unsigned char*)malloc(this->_valueSize);
}

BLECharacteristic::BLECharacteristic(const char* uuid, unsigned char properties, const char* value, bool fixedLength) :
  BLEAttribute(uuid, BLETypeCharacteristic),
  _properties(properties),
  _valueSize(min(strlen(value), BLE_ATTRIBUTE_MAX_VALUE_LENGTH)),
  _valueLength(0),
  _fixedLength(fixedLength),
  _written(false),
  _subscribed(false),
  _listener(NULL)
{
  memset(this->_eventHandlers, 0x00, sizeof(this->_eventHandlers));

  _value = (unsigned char*)malloc(this->_valueSize);
  this->setValue(value);
}

BLECharacteristic::~BLECharacteristic() {
  if (this->_value) {
    free(this->_value);
  }
}

unsigned char BLECharacteristic::properties() const {
  return this->_properties;
}

unsigned char BLECharacteristic::valueSize() const {
  return this->_valueSize;
}

unsigned const char* BLECharacteristic::value() const {
  return this->_value;
}

unsigned char BLECharacteristic::valueLength() const {
  return this->_valueLength;
}

bool BLECharacteristic::fixedLength() const {
  return this->_fixedLength;
}

bool BLECharacteristic::setValue(const unsigned char value[], unsigned char length) {
  bool success = true;

  this->_valueLength = min(length, this->_valueSize);

  memcpy(this->_value, value, this->_valueLength);

  if (this->_listener) {
    success = this->_listener->characteristicValueChanged(*this);
  }

  return success;
}

bool BLECharacteristic::setValue(const char* value) {
  return this->setValue((const unsigned char *)value, strlen(value));
}

bool BLECharacteristic::written() {
  bool written = this->_written;

  if (written) {
    this->_written = false;
  }

  return written;
}

void BLECharacteristic::setValue(BLECentral& central, const unsigned char value[], unsigned char length) {
  this->setValue(value, length);

  this->_written = true;

  BLECharacteristicEventHandler eventHandler = this->_eventHandlers[BLEWritten];
  if (eventHandler) {
    eventHandler(central, *this);
  }
}

bool BLECharacteristic::subscribed() {
  return this->_subscribed;
}

void BLECharacteristic::setSubscribed(BLECentral& central, bool subscribed) {
  this->_subscribed = subscribed;

  BLECharacteristicEventHandler eventHandler = this->_eventHandlers[subscribed ? BLESubscribed : BLEUnsubscribed];

  if (eventHandler) {
    eventHandler(central, *this);
  }
}

bool BLECharacteristic::canNotify() {
  return (this->_listener) ? this->_listener->canNotifyCharacteristic(*this) : false;
}

bool BLECharacteristic::canIndicate() {
  return (this->_listener) ? this->_listener->canIndicateCharacteristic(*this) : false;
}

void BLECharacteristic::setEventHandler(BLECharacteristicEvent event, BLECharacteristicEventHandler eventHandler) {
  if (event < sizeof(this->_eventHandlers)) {
    this->_eventHandlers[event] = eventHandler;
  }
}

void BLECharacteristic::setValueChangeListener(BLECharacteristicValueChangeListener& listener) {
  this->_listener = &listener;
}
