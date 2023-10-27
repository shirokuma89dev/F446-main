/** main.cpp
 * これは聖なるメインプログラム
 * あっぱれ！！あっぱれ！！
 */

// ヘッダファイルの読み込み

#include <Arduino.h>

#include "./device/device.h"

void setup() {
    initDevice();

    uart1.println("Hello, World!");
}

void loop() {
    gyro.read();
    uart1.println(gyro.read());
}