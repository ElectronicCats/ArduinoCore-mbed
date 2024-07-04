#include "Arduino.h"
#include "pinDefinitions.h"

AnalogPinDescription g_AAnalogPinDescription[] = {
  { p26,        NULL },    // A0
};

PinDescription g_APinDescription[] = {
  
  // I2C D0 - D1
  { p4,        NULL, NULL, NULL },    // D0/SDA
  { p5,        NULL, NULL, NULL },    // D1/SCL

  // D2 - D2
  { p8,        NULL, NULL, NULL },    // D2/LED1
  { p9,        NULL, NULL, NULL },    // D3/LED2
  { p10,         NULL, NULL, NULL },    // D4/LED3
  { p17,        NULL, NULL, NULL },    // D5/VEN
  { p18,        NULL, NULL, NULL },    // D6/IRQ
  { p19,        NULL, NULL, NULL },    // D7/GPIO2
  { p20,         NULL, NULL, NULL },    // D8 GPIO0
  { p21,        NULL, NULL, NULL },    // D9 GPIO1
  
  // Analog as digital
  { p26,        NULL, NULL, NULL },    // A0 -> D10
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
