#include "Arduino.h"
#include "pinDefinitions.h"

AnalogPinDescription g_AAnalogPinDescription[] = {
  { p26,        NULL }, // ADC Dummy
};

PinDescription g_APinDescription[] = {
  // D0 - D4
  // Internal pins Radio LoRa
  { p10,        NULL, NULL, NULL },    // D0/DIO0
  { p11,        NULL, NULL, NULL },    // D1/DIO1
  { p12,        NULL, NULL, NULL },    // D2/DIO2
  { p15,        NULL, NULL, NULL },    // D3/DIO5
  
  { p25,        NULL, NULL, NULL },    // D4/RX_LED

  { p21,        NULL, NULL, NULL },    // D5/RFM_RESET
  { p16,         NULL, NULL, NULL },    // D6/SPI_CIPO
  { p17,         NULL, NULL, NULL },    // D7/SPI_CS
  { p19,        NULL, NULL, NULL },    // D8/SPI_COPI
  { p18,        NULL, NULL, NULL },    // D9/SPI_SCK

  { p26,        NULL, NULL, NULL }, // ADC Dummy
};

extern "C" {
  unsigned int PINCOUNT_fn() {
    return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
  }
}

#include "drivers/I2C.h"


void initVariant() {
}

#ifdef SERIAL_CDC

static void utox8(uint32_t val, uint8_t* s) {
  for (int i = 0; i < 16; i=i+2) {
    int d = val & 0XF;
    val = (val >> 4);

    s[15 - i -1] = d > 9 ? 'A' + d - 10 : '0' + d;
    s[15 - i] = '\0';
  }
}

extern "C" {
#include "hardware/flash.h"
#include "pico/bootrom.h"
}

uint8_t getUniqueSerialNumber(uint8_t* name) {
  uint32_t id[2];
  flash_get_unique_id((uint8_t*)&id[0]);
  utox8(id[0], &name[0]);
  utox8(id[1], &name[16]);
  return 32;
}

void _ontouch1200bps_() {
  reset_usb_boot(1 << digitalPinToPinName(LED_BUILTIN), 0);
}

#endif
