/** main.cpp
 * これは聖なるメインプログラム
 * あっぱれ！！あっぱれ！！
 */

// ヘッダファイルの読み込み

#include <Arduino.h>

#include "./device/device.h"

void setup() {
    motorLeftPin[0] = 0;
    motorLeftPin[1] = 0;
    motorRightPin[0] = 0;
    motorRightPin[1] = 0;

    initDevice();

    uart1.println("Hello, World!");
}
int mode = 0;
double gain = 0.99;
int speed = 0;
unsigned long timer = 0;

void loop() {
    int offset = gyro.read();
    offset *= 20;

    uart1.println(offset);

    static int _speed = 0;
    _speed = gain * _speed + (1 - gain) * speed;

    if (uart1.available() > 0) {
        char c = uart1.read();

        if (c == 'w') {
            mode = 1;
            speed = 255;
            timer = millis();
        } else if (c == 's') {
            mode = 2;
            speed = -255;
            timer = millis();
        } else if (c == 'a') {
            mode = 3;
            speed = 0;
        }
    }

    if (mode == 1 || mode == 2) {
        motorL.drive(_speed - offset);
        motorR.drive(_speed + offset);
    } else {
        motorL.drive(0);
        motorR.drive(0);
    }
}