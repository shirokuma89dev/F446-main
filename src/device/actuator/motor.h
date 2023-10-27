#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>
#include "../../kit/IO-Kit.h"

#define REVERSE true
#define LEFT 0
#define RIGHT 1

// dir: direction
// pwm: pulse width modulation / speed

class MOTOR {
   public:
    MOTOR(Output *_dir, Output *_pwm, bool _setReverse = false);
    void drive(int _pwm);

   private:
    Output *dirPtr;
    Output *pwmPtr;

    bool isReverse = false;
};

MOTOR::MOTOR(Output *_dir, Output *_pwm, bool _setReverse) {
    dirPtr = _dir;
    pwmPtr = _pwm;
    isReverse = _setReverse;

    dirPtr->set(LOW);  // reserved
    pwmPtr->setPWM(0);
}

void MOTOR::drive(int _pwm) {
    if (isReverse) _pwm = -1 * _pwm;

    if (_pwm > 0) {
        dirPtr->set(HIGH);
        pwmPtr->setPWM(_pwm);
    } else if (_pwm < 0) {
        dirPtr->set(LOW);
        pwmPtr->setPWM(-_pwm);
    } else {
        dirPtr->set(LOW);  // reserved
        pwmPtr->setPWM(0);
    }
}

#endif