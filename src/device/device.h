#ifndef _DEVICE_H_
#define _DEVICE_H_

#include <Arduino.h>
#include <Wire.h>

#include "./sensor/sensor.h"
#include "./actuator/actuator.h"

HardwareSerial uart1(PA10, PA9);

void initUART(void) {
    uart1.setRx(PA10);
    uart1.setTx(PA9);
    uart1.begin(115200);
}

void initI2C(void) {
    Wire.setSDA(PB9);
    Wire.setSCL(PB8);
    Wire.begin();
}

void initDevice(void) {
    // set motors to stop ASAP
    for (int i = 0; i < 2; i++) {
        motor[i].drive(0);
    }

    initI2C();
    initUART();

    gyro.init();
    gyro.setOffset();

    buzzer.bootSound();
}

#endif
