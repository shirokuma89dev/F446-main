#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include "Arduino.h"

#include "buzzer.h"
#include "motor.h"

Output buzzerPin = Output(PB6);
BUZZER buzzer(&buzzerPin);

HardwareSerial uart5(PD2, PC12);  // 空きポート

Output motorRightPin[2] = {Output(PC7), Output(PC6)};
Output motorLeftPin[2] = {Output(PC0), Output(PB15)};

MOTOR motorL(&motorLeftPin[0], &motorLeftPin[1]);
MOTOR motorR(&motorRightPin[0], &motorRightPin[1], true);

#endif