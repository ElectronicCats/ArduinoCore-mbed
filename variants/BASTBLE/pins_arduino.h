#pragma once
#include <stdint.h>
#include <macros.h>

#ifndef __PINS_ARDUINO__
#define __PINS_ARDUINO__

#define ANALOG_CONFIG

/* Analog reference options 
 * Different possibilities available combining Reference and Gain
 */
enum _AnalogReferenceMode
{
  AR_VDD,         // 3.3 V
  AR_INTERNAL,    // 0.6 V
  AR_INTERNAL1V2, // 1.2 V
  AR_INTERNAL2V4  // 2.4 V
};

/* Analog acquisition time options */
enum _AnalogAcquisitionTime
{
  AT_3_US,         
  AT_5_US,    
  AT_10_US, // Default value
  AT_15_US,
  AT_20_US,  
  AT_40_US  
};

// Frequency of the board main oscillator
#define VARIANT_MAINOSC (32768ul)

// Master clock frequency
#define VARIANT_MCK     (64000000ul)

// Pins
// ----

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (27u)
#define NUM_ANALOG_INPUTS    (7u)
#define NUM_ANALOG_OUTPUTS   (0u)

// LEDs
// ----
#define PIN_LED     (14u)
#define LED_BUILTIN PIN_LED

// On-board SPI Flash
#define EXTERNAL_FLASH_DEVICES  GD25Q16C
#define EXTERNAL_FLASH_USE_QSPI  SPI1
#define EXTERNAL_FLASH_USE_CS   SS1

// Analog pins
// -----------
#define PIN_A0 (15u)
#define PIN_A1 (16u)
#define PIN_A2 (17u)
#define PIN_A3 (18u)
#define PIN_A4 (19u)
#define PIN_A5 (20u)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;

#define ADC_RESOLUTION 12

// Digital pins
// -----------
#define D0   0
#define D1   1
#define D2   2
#define D3   3
#define D4   4
#define D5   5
#define D6   6
#define D7   7
#define D8   8
#define D9   9
#define D10  10
#define D11  11
#define D12  12
#define D13  13

/*
 * Serial interfaces
 */
// Serial (EDBG)
#define PIN_SERIAL_RX (1ul)
#define PIN_SERIAL_TX (0ul)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2 //SPI on pins

#define PIN_SPI_MISO  (8u)
#define PIN_SPI_MOSI  (7u)
#define PIN_SPI_SCK   (4u)
#define PIN_SPI_SS    (10u)

static const uint8_t SS   = PIN_SPI_SS;   // SPI Slave SS not used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_SPI1_MISO         (11u)
#define PIN_SPI1_MOSI         (8u)
#define PIN_SPI1_SCK          (9u) 
#define PIN_SPI1_SS           (10u)

static const uint8_t SS1   = PIN_SPI1_SS ;
static const uint8_t MOSI1 = PIN_SPI1_MOSI ;
static const uint8_t MISO1 = PIN_SPI1_MISO ;
static const uint8_t SCK1  = PIN_SPI1_SCK ;

// Wire
#define PIN_WIRE_SDA        (2u)
#define PIN_WIRE_SCL        (3u)

// PDM Interfaces
// ---------------
#define PIN_PDM_PWR	 (15)
#define PIN_PDM_CLK	 (16)
#define PIN_PDM_DIN	 (17)

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1
#define Serial                      SerialUSB

// Mbed specific defines
#define SERIAL_HOWMANY		1
#define SERIAL1_TX			(digitalPinToPinName(PIN_SERIAL_TX))
#define SERIAL1_RX			(digitalPinToPinName(PIN_SERIAL_RX))

#define SERIAL_CDC			1
#define HAS_UNIQUE_ISERIAL_DESCRIPTOR
#define BOARD_VENDORID		0x2341
#define BOARD_PRODUCTID		0x805a
#define BOARD_NAME			"Bast BLE"

#define DFU_MAGIC_SERIAL_ONLY_RESET   0xb0

#define WIRE_HOWMANY		1

#define I2C_SDA				(digitalPinToPinName(PIN_WIRE_SDA))
#define I2C_SCL				(digitalPinToPinName(PIN_WIRE_SCL))

#define SPI_HOWMANY			2

#define SPI_MISO			(digitalPinToPinName(PIN_SPI_MISO))
#define SPI_MOSI			(digitalPinToPinName(PIN_SPI_MOSI))
#define SPI_SCK				(digitalPinToPinName(PIN_SPI_SCK))

#define SPI1_MISO			(digitalPinToPinName(PIN_SPI1_MISO))
#define SPI1_MOSI			(digitalPinToPinName(PIN_SPI1_MOSI))
#define SPI1_SCK			(digitalPinToPinName(PIN_SPI1_SCK))

#define digitalPinToPort(P)		(digitalPinToPinName(P)/33)

uint8_t getUniqueSerialNumber(uint8_t* name);
void _ontouch1200bps_();

#endif //__PINS_ARDUINO__
