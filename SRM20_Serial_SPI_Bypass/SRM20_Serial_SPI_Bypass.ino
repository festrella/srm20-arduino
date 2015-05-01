#include <SPI.h>
#include <SRM20SPIRemote.h>

SRM20SPIRemote srm20;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
long rpm;

void setup(){
  Serial.begin(9600);
  srm20.begin(9,6);
  inputString.reserve(200);
}

void loop(){
  if (stringComplete) {
    if(!inputString.startsWith("rotate")){
      Serial.println("not a valid command");
    } else {
      inputString.replace("rotate","");
      rpm = inputString.toInt();
      if(rpm>0 || rpm==0){
        srm20.turnSpindle(rpm);
        Serial.print("Set speed: ");
        Serial.println(inputString);
      } else {
        Serial.println("not a number");
      } 
    }
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

