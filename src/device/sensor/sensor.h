#ifndef _INPUT_H_
#define _INPUT_H_

#include <Arduino.h>

#include <Wire.h>

#include "gyro.h"

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire);
HardwareSerial uart4(PA1, PA0);

GYRO gyro(&bno);

HardwareSerial uart2(PA3, PA2);
// HardwareSerial uart6(PC7, PC6);

#endif