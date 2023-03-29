#include "Arduino.h"
#include "WriteMotor.h"

/*
  Конструктор, принимающий пин для управления направлением (_pinDirection)
  и ШИМ-пин для правления скоростью (_pinInput)
*/
Motor::Motor(int8_t _pinDirection, int8_t _pinInput) {
  pinDirection = _pinDirection;
  pinInput = _pinInput;
}

//Изменение вращения на противоположное
void Motor::revers() {
  reverse *= -1;
  writeMotor(reverse, value);
}

//Изменение вращения на противоположное с указанием конечной скорости
void Motor::revers(int value) {
  reverse *= -1;
  writeMotor(reverse, value);
}

/*
  Определение направления вращения:
  Если значение revers равно 1, то направление FORWARD будет направлением вперёд
  Если значение revers равно -1, то направление FORWARD будет направлением назад
  Если значение revers равно 0, то направление меняться не будет.
*/
void Motor::setRevers(int8_t revers) {
  anty_reverse = (revers > 0) ? 1 : ((revers < 0) ? -1 : 0);
  reverse = -1 * revers;
}

//Остановка мотора
void Motor::stop() {
  writeMotor(STOP, 0);
}

//Задание скорсоти мотора без  указания вращения мотора
void Motor::writeMotor(int value) {
  writeMotor(reverse, value);
}

//Задание скорости и направления вращения мотора
void Motor::writeMotor(int value, int8_t revers) {
  if (revers * anty_reverse > 0) {
    reverse = FORWARD;
    analogWrite(pinInput, getValueLimit(value));
  } else if (revers * anty_reverse < 0) {
    reverse = BACK;
    analogWrite(pinInput, MAX_VALUE - getValueLimit(value));
  } else {
    reverse = STOP;
    analogWrite(pinInput, MIN_VALUE);
  }
  digitalWrite(pinDirection, reverse * anty_reverse < 0);
  reverse *= anty_reverse;
}

//Ограничение по скорости вращения
int Motor::getValueLimit(int value) {
  return constrain(value, MIN_VALUE, MAX_VALUE);
}

/*
  Возвращение направления вращения
  При остановки мотора возвращает 0
*/
int8_t Motor::getRevers() {
  return reverse;
}

//Возвращение скорости мотора
int Motor::getValue() {
  return value;
}

/*
  Коструктор, принимающий пины для управления направлением (_pinDirection1 и _pinDirection2)
  и пины для управлением скоростью (_pinInput1 и _pinInput2) моторов (левого и правого)
*/
WriteMotor::WriteMotor(int8_t _pinDirection1, int8_t _pinInput1, int8_t _pinDirection2, int8_t _pinInput2) {
  motor1 = Motor(_pinDirection1, _pinInput1);
  motor2 = Motor(_pinDirection2, _pinInput2);
}

//Изменение направления на противоположное для всех моторов
void WriteMotor::revers() {
  motor1.revers();
  motor2.revers();
}

//Изменение напрвления на противоположное с указанием конечной скорости
void WriteMotor::revers(int value) {
  motor1.revers(value);
  motor2.revers(value);
}

//Изменение направления на противоположное для определённого мотора
void WriteMotor::revers(int8_t motor) {
  if (motor == MOTOR1)
    motor1.revers();
  if (motor == MOTOR2)
    motor2.revers();
}

//Изменение напрвления на противоположное для опрделённого мотора с укаязанием скорости
void WriteMotor::revers(int8_t motor, int value) {
  if (motor == MOTOR1)
    motor1.revers(value);
  if (motor == MOTOR2)
    motor2.revers(value);
}

//Определнеи направления для всех моторов
void WriteMotor::setRevers(int8_t revers) {
  motor1.setRevers(revers);
  motor2.setRevers(revers);
}

//Определение направления для определённого мотора
void WriteMotor::setRevers(int8_t motor, int8_t revers) {
  if (motor == MOTOR1)
    motor1.setRevers(revers);
  if (motor == MOTOR2)
    motor2.setRevers(revers);
}

//остановка всех моторов
void WriteMotor::stop() {
  motor1.stop();
  motor2.stop();
}

//Остановка определённого мотора
void WriteMotor::stop(int8_t motor) {
  if (motor == MOTOR1)
    motor1.stop();
  if (motor == MOTOR2)
    motor2.stop();
}

//Задание скорости для всех моторов без изменения направления вращения
void WriteMotor::writeMotor(int value) {
  motor1.writeMotor(value);
  motor2.writeMotor(value);
}

//Задание скорости для определённого мотора
void WriteMotor::writeMotor(int8_t motor, int value) {
  if (motor == MOTOR1)
    motor1.writeMotor(value);
  if (motor == MOTOR2)
    motor2.writeMotor(value);
}

//Задание скорости и направления вращения для определённого мотора
void WriteMotor::writeMotor(int8_t motor, int value, int8_t revers) {
  if (motor == MOTOR1)
    motor1.writeMotor(value, revers);
  if (motor == MOTOR2)
    motor2.writeMotor(value, revers);
}

//Возвращение направления определёного мотора
int8_t WriteMotor::getRevers(int8_t motor) {
  int8_t revers = 0;
  if (motor == MOTOR1)
    revers = motor1.getRevers();
  if (motor == MOTOR2)
    revers = motor2.getRevers();
  return revers;
}

//Возвращение скорости определённого мотора
int WriteMotor::getValue(int8_t motor) {
  int value = 0;
  if (motor == MOTOR1)
    value = motor1.getValue();
  if (motor == MOTOR2)
    value = motor2.getValue();
  return value;
}

//Возвращение объекта мотора 1 (левый)
Motor WriteMotor::getMotor1() {
  return motor1;
}

//Возвращение объекта мотора 2 (правый)
Motor WriteMotor::getMotor2() {
  return motor2;
}

//Возвращение объекта определённого мотора
Motor WriteMotor::getMotor(int8_t motor) {
  if (motor == MOTOR1)
    return motor1;
  if (motor == MOTOR2)
    return motor2;
  return motor1;
}
