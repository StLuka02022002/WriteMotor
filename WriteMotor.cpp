#include "HardwareSerial.h"
#include "Arduino.h"
#include <stdint.h>
#include "WriteMotor.h"

Motor::Motor(int8_t pinDirection, int8_t pinInput) :
  pinDirection(pinDirection), pinInput(pinInput) {}

void Motor::revers() {
  reverse *= -1;
  writeMotor(reverse, value);
}

void Motor::revers(int value) {
  reverse *= -1;
  writeMotor(reverse, value);
}

void Motor::setRevers(int8_t revers) {
  anty_reverse = (revers > 0) ? 1 : ((revers < 0) ? -1 : 0);
  reverse = -1 * revers;
}

void Motor::stop() {
  writeMotor(STOP, 0);
}

void Motor::writeMotor(int value) {
  writeMotor(reverse, value);
}

void Motor::writeMotor(int8_t revers, int value) {
  if (revers * anty_reverse > 0) {
    reverse = FORWARD;
    analogWrite(pinInput, constrain(value, MIN_VALUE, MAX_VALUE));
  } else if (revers * anty_reverse < 0) {
    reverse = BACK;
    analogWrite(pinInput, MAX_VALUE - constrain(value, MIN_VALUE, MAX_VALUE));
  } else {
    reverse = STOP;
    analogWrite(pinInput, MIN_VALUE);
  }
  digitalWrite(pinDirection, reverse * anty_reverse < 0);
  reverse *= anty_reverse;
}

int8_t Motor::getRevers() {
  return reverse;
}

int Motor::getValue() {
  return value;
}
