#define LEFT_FOOT 4

#include <Servo.h>

Servo LeftLeg;  

void setup() {
  LeftLeg.attach(LEFT_FOOT);
}

void loop() {
  LeftLeg.write(0);   delay(500);
  LeftLeg.write(45);  delay(500);
  LeftLeg.write(90);  delay(500);
  LeftLeg.write(135); delay(500);
  LeftLeg.write(180); delay(500);
  LeftLeg.write(135); delay(500);
  LeftLeg.write(90);  delay(500);
  LeftLeg.write(45);  delay(500);
}
