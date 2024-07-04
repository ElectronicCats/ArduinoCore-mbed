#pragma once
#include <macros.h>
#include <stdint.h>

#ifndef __PINS_ARDUINO__
#define __PINS_ARDUINO__

#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif

// Pin count
// ----
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (10u)
#define NUM_ANALOG_INPUTS    (1u)
#define NUM_ANALOG_OUTPUTS   (0u)

extern PinName digitalPinToPinName(pin_size_t P);

// LEDs
// ----
#define PIN_LED     (2u)
#define LED_BUILTIN PIN_LED

// Analog pins
// -----------
#define PIN_A0 (10u)

static const uint8_t A0  = PIN_A0;

#define ADC_RESOLUTION 12

// Wire
#define PIN_WIRE_SDA        (0u)
#define PIN_WIRE_SCL        (1u)

#define SERIAL_HOWMANY		0

#define SERIAL_CDC			1
#define HAS_UNIQUE_ISERIAL_DESCRIPTOR
#define BOARD_VENDORID		0x1209
#define BOARD_PRODUCTID		0x005e
#define BOARD_NAME			"Hunter Cat NFC 2040"

uint8_t getUniqueSerialNumber(uint8_t* name);
void _ontouch1200bps_();

#define SPI_HOWMANY		(0)

#define WIRE_HOWMANY	(1)
#define I2C_HW			(i2c0)
#define I2C_SDA			(digitalPinToPinName(PIN_WIRE_SDA))
#define I2C_SCL			(digitalPinToPinName(PIN_WIRE_SCL))

#define digitalPinToPort(P)		(digitalPinToPinName(P)/32)

#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB

#define USB_MAX_POWER	(500)

#endif //__PINS_ARDUINO__
