#include <SPI.h>
#include <SRM20SPIRemote.h>

SRM20SPIRemote srm20;

void setup(){
  Serial.begin(9600);
  srm20.begin(9,6);
  attachInterrupt(0,forceStop,CHANGE);
}

void loop(){
}

void forceStop(){
  srm20.stopMoving();
  srm20.turnSpindle(0);
  Serial.println("EMERGENCY STOP");
}
