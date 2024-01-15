#pragma once

#include <SD.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// libc++ definitions
#define EXIT_FAILURE 1

// library parameters
#define SD_CARD_CSPIN 12 // sd card chip select pin

// definitions
#define BUTTON_ONE 12
#define BUTTON_TWO 13
#define MPU_ADDR 0x68