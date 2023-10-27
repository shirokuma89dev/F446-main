/** main.cpp
 * これは聖なるメインプログラム
 * あっぱれ！！あっぱれ！！
 */

#include <Arduino.h>
#include "./device/device.h"

void setup() {
    initDevice();
    uart1.println("Hello, World!");
}

int calcControlValue(GYRO *_gyroPtr) {
    const int Kp = 20.0;
    const int error = _gyroPtr->read();

    int controlVal = Kp * error;  // Proportional

    return controlVal;
}

int rcFilter(int _input) {
    const double gain = 0.99;
    static int output = 0;

    output = gain * output + (1 - gain) * _input;
    return output;
}

void loop() {
    static int commandSpeed = 0;  // 指令値

    if (char data = uart1.read() != -1) {
        const char UP = 'w';
        const char DOWN = 's';
        const char STOP = 'a';

        switch (data) {
            case UP:
                commandSpeed = 255;
                break;

            case DOWN:
                commandSpeed = -255;
                break;

            case STOP:
                commandSpeed = 0;
                break;
        }
    }

    // 駆動
    if (commandSpeed != 0) {
        int controlVal = calcControlValue(&gyro);
        int speed = rcFilter(commandSpeed);

        motor[LEFT].drive(speed - controlVal);
        motor[RIGHT].drive(speed + controlVal);
    } else {
        for (int i = 0; i < 2; i++) {
            motor[i].drive(0);
        }
    }
}