#define rmt_CHAm 0x45
#define rmt_CHAN 0x46
#define rmt_CHAp 0x47
#define rmt_PREV 0x44
#define rmt_NEXT 0x40
#define rmt_PLAY 0x43
#define rmt_VOLm 0x07
#define rmt_VOLp 0x15
#define rmt_EQ   0x09
#define rmt_100p 0x19
#define rmt_200p 0x0D

#define rmt_0   0x16
#define rmt_1   0x0C
#define rmt_2   0x18
#define rmt_3   0x5E
#define rmt_4   0x08
#define rmt_5   0x1C
#define rmt_6   0x5A
#define rmt_7   0x42
#define rmt_8   0x52
#define rmt_9   0x4A

#include <Otto.h>
#include <IRremote.h>
Otto Otto;  

#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer  13 // not used

#define IR_RECEIVE_PIN 10

void setup()
{
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer); //Set the servo pins and Buzzer pin
  IrReceiver.begin(IR_RECEIVE_PIN);
  
  Otto.home();
  delay(500);
}
void loop()
{
  if (IrReceiver.decode()) 
  {
    unsigned char cmd = IrReceiver.decodedIRData.command;
    
    if(cmd == rmt_CHAm)      {Otto.walk(2,1200,-1);} // step back
    else if(cmd == rmt_CHAN) {Otto.home();}
    else if(cmd == rmt_CHAp) {Otto.walk(2,1200,1);} // step forward
    
    else if(cmd == rmt_PREV) {Otto.moonwalker(3, 1000, 25,-1);} 
    else if(cmd == rmt_NEXT) {Otto.moonwalker(3, 1000, 25,1);}
    else if(cmd == rmt_PLAY) { /*nothing*/}
    
    else if(cmd == rmt_VOLm) {Otto.turn(2,1000,1);}
    else if(cmd == rmt_VOLp) {Otto.turn(2,1000,-1);}
    else if(cmd == rmt_EQ  ) {/*nothing*/}
    
    else if(cmd == rmt_0   ) {/*nothing*/}
    else if(cmd == rmt_100p) {/*nothing*/}
    else if(cmd == rmt_200p) {/*nothing*/}

    else if(cmd == rmt_1   ) {/*nothing*/}
    else if(cmd == rmt_2   ) {/*nothing*/}
    else if(cmd == rmt_3   ) {/*nothing*/}

    else if(cmd == rmt_4   ) {/*nothing*/}
    else if(cmd == rmt_5   ) {/*nothing*/}
    else if(cmd == rmt_6   ) {/*nothing*/}

    else if(cmd == rmt_7   ) {/*nothing*/}
    else if(cmd == rmt_8   ) {/*nothing*/}
    else if(cmd == rmt_9   ) {/*nothing*/}
    
    IrReceiver.resume();
    
  } 
}
