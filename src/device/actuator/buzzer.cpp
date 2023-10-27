#include "buzzer.h"

BUZZER::BUZZER(Output *pinPtr) {
    this->pinPtr = pinPtr;
}

void BUZZER::setFrequency(int freq) {
    if (isDisabled) return;

    analogWriteFrequency(freq);
    pinPtr->setPWM(60);
}

void BUZZER::mute(void) {
    pinPtr->setPWM(0);
}

void BUZZER::bootSound(void) {
    setFrequency(440);
    delay(100);
    setFrequency(880);
    delay(100);
    mute();
}