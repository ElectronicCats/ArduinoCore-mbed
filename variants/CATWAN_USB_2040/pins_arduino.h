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
#define PIN_LED     (4u)
#define LED_BUILTIN PIN_LED

#define RFM_RST (5u)
#define RFM_DIO0 (0u)
#define RFM_DIO1 (1u)
#define RFM_DIO2 (2u)
#define RFM_DIO5 (5u)

// Analog pins
// -----------
#define PIN_A0 (10u)

static const uint8_t A0  = PIN_A0;

#define ADC_RESOLUTION 12

// SPI
#define PIN_SPI_MISO  (6u)
#define PIN_SPI_MOSI  (8u)
#define PIN_SPI_SCK   (9u)
#define PIN_SPI_SS    (7u)

static const uint8_t SS   = PIN_SPI_SS;   // SPI Slave SS not used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define SERIAL_HOWMANY		0


#define SERIAL_CDC			1
#define HAS_UNIQUE_ISERIAL_DESCRIPTOR
#define BOARD_VENDORID		0x2341
#define BOARD_PRODUCTID		0x005e
#define BOARD_NAME			"CatWan USBStick2040"

uint8_t getUniqueSerialNumber(uint8_t* name);
void _ontouch1200bps_();

#define SPI_HOWMANY		(1)
#define SPI_MISO		(digitalPinToPinName(PIN_SPI_MISO))
#define SPI_MOSI		(digitalPinToPinName(PIN_SPI_MOSI))
#define SPI_SCK			(digitalPinToPinName(PIN_SPI_SCK))

#define WIRE_HOWMANY	(0)

#define digitalPinToPort(P)		(digitalPinToPinName(P)/32)

#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB

#define USB_MAX_POWER	(500)

#endif //__PINS_ARDUINO__
