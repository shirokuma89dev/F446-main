#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>
#include "../../kit/IO-Kit.h"

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

    dirPtr->set(0);
    pwmPtr->setPWM(0);
    
    isReverse = _setReverse;
}

void MOTOR::drive(int _pwm) {
    if (isReverse) _pwm = -_pwm;

    if (_pwm > 0) {
        dirPtr->set(1);
        pwmPtr->setPWM(_pwm);
    } else if (_pwm < 0) {
        dirPtr->set(0);
        pwmPtr->setPWM(-_pwm);
    } else {
        dirPtr->set(0);
        pwmPtr->setPWM(0);
    }
}   


#endif