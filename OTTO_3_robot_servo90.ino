#include <Servo.h>

#define LL 2 
#define RL 3
#define LF 4 
#define RF 5 
Servo leftLeg;
Servo rightLeg;
Servo leftFoot;
Servo rightFoot;

void setup()
{
  leftLeg.attach(LL);
  rightLeg.attach(RL);
  leftFoot.attach(LF);
  rightFoot.attach(RF);

  leftLeg.write(90);
  rightLeg.write(90);
  leftFoot.write(90);
  rightFoot.write(90);
}

void loop(){  
}
