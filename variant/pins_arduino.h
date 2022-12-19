#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define USB_MANUFACTURER "HarveyBates"
#define USB_PRODUCT "ESP32-Clover"
#define USB_SERIAL ""

#define EXTERNAL_NUM_INTERRUPTS 46
#define NUM_DIGITAL_PINS        48
#define NUM_ANALOG_INPUTS       20

#define analogInputToDigitalPin(p)  (((p)<20)?(analogChannelToDigitalPin(p)):-1)
#define digitalPinToInterrupt(p)    (((p)<48)?(p):-1)
#define digitalPinHasPWM(p)         (p < 46)

// Builtin LED
// TODO implement masking on digitalWrite
static const uint8_t LED_BUILTIN = 0 & 0x6F;
#define BUILTIN_LED  LED_BUILTIN // backward compatibility

// Primary UART pins
#define TX0 34
#define RX0 33
static const uint8_t TX = 34;
static const uint8_t RX = 33;

// Seconadary UART pins
#define TX1 36
#define RX1 11

// I2C pins (has 10K resistors builtin)
static const uint8_t SCL = 37;
static const uint8_t SDA = 10;

// SPI pins (see below for chip select lines)
static const uint8_t MOSI  = 30;
static const uint8_t MISO  = 31;
static const uint8_t SCK   = 29;

// Piezo control pin
static const uint8_t BUILTIN_PIEZO = 12;

// Digital to analog converter I2c address
static const uint8_t DAC_ADDR = 0x7C;

// Analog to digital converter ADC chip select
static const uint8_t ADC_CS = 26;

// Analog to digital pins
static const uint8_t IN1 = 1 & 0x7F;
static const uint8_t IN2 = 2 & 0x7F;
static const uint8_t IN3 = 3 & 0x7F;
static const uint8_t IN4 = 4 & 0x7F;

// External IO I2C address
static const uint8_t EX_IO_ADDR = 0x20;

// Interrupt for external IO (TCA9534 chip)
static const uint8_t EX_IO_INT = 33;

// External IO pin defs
static const uint8_t P0 = 0 & 0x6F; // Same as BUILTIN_LED
static const uint8_t P1 = 1 & 0x6F;
static const uint8_t P2 = 2 & 0x6F;
static const uint8_t P3 = 3 & 0x6F;
static const uint8_t P4 = 4 & 0x6F;
static const uint8_t P5 = 5 & 0x6F;
static const uint8_t P6 = 6 & 0x6F;
static const uint8_t P7 = 7 & 0x6F;

// Interrupt pin for builtin programmable button
static const uint8_t BUILTIN_PROG_BTN = 6;

#endif /* Pins_Arduino_h */
