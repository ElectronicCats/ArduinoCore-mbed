#include "Arduino.h"
#include "pinDefinitions.h"

AnalogPinDescription g_AAnalogPinDescription[] = {
  { p26,        NULL },    // A0
  { p27,        NULL },    // A1
  { p28,        NULL },    // A2
  { p29,        NULL },    // A3
};

PinDescription g_APinDescription[] = {
  // D0 - D29
  { p0,  NULL, NULL, NULL }, // TX
  { p1,  NULL, NULL, NULL }, // RX
  { p2,  NULL, NULL, NULL }, // CTS
  { p3,  NULL, NULL, NULL }, // RTS
  { p4,  NULL, NULL, NULL }, // BUSY
  { p5,  NULL, NULL, NULL }, // DIO1
  { p6,  NULL, NULL, NULL }, // NC
  { p7,  NULL, NULL, NULL }, // NC
  { p8,  NULL, NULL, NULL }, // CTF1
  { p9,  NULL, NULL, NULL }, // CTF2
  { p10, NULL, NULL, NULL }, // CTF3
  { p11, NULL, NULL, NULL }, // TCK
  { p12, NULL, NULL, NULL }, // TMSC
  { p13, NULL, NULL, NULL }, // TDI
  { p14, NULL, NULL, NULL }, // TDO
  { p15, NULL, NULL, NULL }, // RST_CC
  { p16, NULL, NULL, NULL }, // CIPO
  { p17, NULL, NULL, NULL }, // NSS
  { p18, NULL, NULL, NULL }, // SCK
  { p19, NULL, NULL, NULL }, // COPI
  { p20, NULL, NULL, NULL }, // ANT_SW
  { p21, NULL, NULL, NULL }, // DIO22
  { p22, NULL, NULL, NULL }, // NC
  { p23, NULL, NULL, NULL }, // DIO2
  { p24, NULL, NULL, NULL }, // RST_SX RADIO LORA
  { p25, NULL, NULL, NULL }, // DIO3
  { p26, NULL, NULL, NULL }, // LED3
  { p27, NULL, NULL, NULL }, // LED2
  { p28, NULL, NULL, NULL }, // LED1
  { p29, NULL, NULL, NULL }, // NC
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
