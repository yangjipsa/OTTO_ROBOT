#include <IRremote.h>
#define IR_RECEIVE_PIN 10

void setup()
{
  IrReceiver.begin(IR_RECEIVE_PIN);
  Serial.begin(9600);
  Serial.println("** IR Receiver Test **");
}

void loop()
{
  if (IrReceiver.decode()) 
  {
    delay(200);
    unsigned char cmd = IrReceiver.decodedIRData.command;
    Serial.print("Received Code : 0x");
    Serial.println(cmd,HEX);

    IrReceiver.resume();
  }
}

