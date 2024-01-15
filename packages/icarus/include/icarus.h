#pragma once

#include <SD.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Adafruit_BMP085.h>

#include "setup.h"
#include "utils.h"

// libc++ definitions
#define EXIT_FAILURE 1
#define TRUE 1 // for some fucking reason, true isnt defined (or maybe im wrong)

// library parameters
#define SD_CARD_CSPIN 12 // sd card chip select pin

#define READ_WIRE(wire) wire.read() << 8 | wire.read()

// definitions
#define BUTTON_ONE 12
#define BUTTON_TWO 13
#define MPU_ADDR 0x68