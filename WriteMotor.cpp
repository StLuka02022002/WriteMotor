#include "HardwareSerial.h"
#include "Arduino.h"
#include <stdint.h>
#include "WriteMotor.h"

Motor::Motor(int8_t _pinDirection, int8_t _pinInput) {
  pinDirection = _pinDirection;
  pinInput = _pinInput;
}

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

void Motor::writeMotor(int value, int8_t revers) {
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

void WriteMotor::begin(int8_t _pinDirection1, int8_t _pinInput1, int8_t _pinDirection2, int8_t _pinInput2) {
  motor1 = Motor(_pinDirection1, _pinInput1);
  motor2 = Motor(_pinDirection2, _pinInput2);
}

void WriteMotor::revers() {
  motor1.revers();
  motor2.revers();
}

void WriteMotor::revers(int value) {
  motor1.revers(value);
  motor2.revers(value);
}

void WriteMotor::revers(int8_t motor) {
  if (motor == MOTOR1)
    motor1.revers();
  if (motor == MOTOR2)
    motor2.revers();
}

void WriteMotor::revers(int8_t motor, int value) {
  if (motor == MOTOR1)
    motor1.revers(value);
  if (motor == MOTOR2)
    motor2.revers(value);
}

void WriteMotor::setRevers(int8_t revers) {
  motor1.setRevers(revers);
  motor2.setRevers(revers);
}

void WriteMotor::setRevers(int8_t motor, int8_t revers) {
  if (motor == MOTOR1)
    motor1.setRevers(revers);
  if (motor == MOTOR2)
    motor2.setRevers(revers);
}

void WriteMotor::stop() {
  motor1.stop();
  motor2.stop();
}

void WriteMotor::stop(int8_t motor) {
  if (motor == MOTOR1)
    motor1.stop();
  if (motor == MOTOR2)
    motor2.stop();
}

void WriteMotor::writeMotor(int value) {
  motor1.writeMotor(value);
  motor2.writeMotor(value);
}

void WriteMotor::writeMotor(int8_t motor, int value) {
  if (motor == MOTOR1)
    motor1.writeMotor(value);
  if (motor == MOTOR2)
    motor2.writeMotor(value);
}

void WriteMotor::writeMotor(int8_t motor, int value, int8_t revers) {
  if (motor == MOTOR1)
    motor1.writeMotor(value, revers);
  if (motor == MOTOR2)
    motor2.writeMotor(value, revers);
}

int8_t WriteMotor::getRevers(int8_t motor) {
  int8_t revers = 0;
  if (motor == MOTOR1)
    revers = motor1.getRevers();
  if (motor == MOTOR2)
    revers = motor2.getRevers();
  return revers;
}

Motor WriteMotor::getMotor1() {
  return motor1;
}

Motor WriteMotor::getMotor2() {
  return motor2;
}

Motor WriteMotor::getMotor(int8_t motor) {
  if (motor == MOTOR1)
    return motor1;
  if (motor == MOTOR2)
    return motor2;
  return motor1;
}
