#include "WriteMotor.h"

Motor motor(2, 3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  motor.writeMotor(255);
  delay(6000);
  motor.revers();
  Serial.print("Motor reverse - ");
  Serial.println(motor.getRevers());
  delay(6000);
  motor.revers(100);
  Serial.print("Motor reverse - ");
  Serial.println(motor.getRevers());
  Serial.print("Motor value - ");
  Serial.println(motor.getValue());
  delay(6000);
  motor.stop();
  Serial.println("Motor stop");
  delay(6000);
}