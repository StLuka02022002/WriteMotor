#include "WriteMotor.h"

WriteMotor motor(2, 3, 4, 5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.writeMotor(MOTOR1, 255, FORWARD);
  motor.writeMotor(MOTOR2, 255, BACK);
  delay(6000);
  motor.revers();
  delay(6000);
  motor.revers(MOTOR1);
  Serial.print("Motor1 revers: ");
  Serial.println(motor.getRevers(MOTOR1));
  Serial.print("Motor2 revers: ");
  Serial.println(motor.getRevers(MOTOR2));
  delay(6000);
  motor.writeMotor(120);
  Serial.print("Motor1 value: ");
  Serial.println(motor.getValue(MOTOR1));
  Serial.print("Motor2 value: ");
  Serial.println(motor.getValue(MOTOR2));
  delay(6000);
  Serial.println("Stop");
  delay(6000);
}
