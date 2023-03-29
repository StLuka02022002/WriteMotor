#ifndef WriteMotor_h
#define WriteMotor_h

#include <Arduino.h>

#define FORWARD 1
#define BACK -1
#define STOP 0
#define MOTOR1 1
#define MOTOR2 2
#define MIN_VALUE 0
#define MAX_VALUE 255

class WriteMotor;

class Motor;

class Motor {
public:
  Motor() = default;
  Motor(int8_t _pinDirection, int8_t _pinInput);
  void revers();
  void revers(int _value);
  void setRevers(int8_t _revers);
  void stop();
  void writeMotor(int _value);
  void writeMotor(int _value, int8_t _revers);
  int8_t getRevers();
  int getValue();
private:
  int8_t pinDirection;
  int8_t pinInput;
  int8_t reverse = FORWARD;
  int8_t anty_reverse = 1;
  int value = MIN_VALUE;
  int getValueLimit(int value);
};

class WriteMotor {
public:
  WriteMotor(int8_t _pinDirection1, int8_t _pinInput1, int8_t _pinDirection2, int8_t _pinInput2);
  void revers();
  void revers(int value);
  void revers(int8_t motor);
  void revers(int8_t motor, int value);
  void setRevers(int8_t revers);
  void setRevers(int8_t motor, int8_t revers);
  void stop();
  void stop(int8_t motor);
  void writeMotor(int value);
  void writeMotor(int8_t motor, int value);
  void writeMotor(int8_t motor, int value, int8_t revers);
  int8_t getRevers(int8_t motor);
  int getValue(int8_t motor);
  Motor getMotor(int8_t motor);
  Motor getMotor1();
  Motor getMotor2();
private:
  Motor motor1;
  Motor motor2;
};

#endif
