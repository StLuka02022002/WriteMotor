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

class Motor {
public:
  Motor(int8_t pinDirection, int8_t pinInput);
  void revers();
  void revers(int value);
  void setRevers(int8_t revers);
  void stop();
  void writeMotor(int value);
  void writeMotor(int8_t revers, int value);
  int8_t getRevers();
  int getValue();
private:
  int8_t pinDirection;
  int8_t pinInput;
  int8_t reverse = STOP;
  int8_t anty_reverse = 1;
  int value = MIN_VALUE;
};

#endif
