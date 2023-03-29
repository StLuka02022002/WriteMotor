#include "WriteMotor.h"
WriteMotor motors(2, 3, 4, 5);
Motor motor1;
Motor motor2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor1 = motors.getMotor1();
  motor2 = motors.getMotor2();
}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.writeMotor(255);
  motor2.writeMotor(250, BACK);
  delay(6000);
  motor1.revers();
  motor2.writeMotor(100, FORWARD);
  delay(6000);
  Serial.print("Motor1 value: ");
  Serial.println(motor1.getValue());
  Serial.println("Motor2 reverse: ");
  Serial.println(motor2.getRevers());
  motor1.stop();
  motor2.stop();
}
