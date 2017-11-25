#include <IRLibSendBase.h>
#include <IRLib_P01_NEC.h>

IRsendNEC mySender;
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState;
int buttonCounter = 0;
const int lightSensorPin = A0;
int lightValue = 0;
const int goalLightValue = 630;
int i = 0;
int tmp = 0;
int increment;

void setup() {
  Serial.begin(9600);
  delay(2000); //delay
  Serial.println(F("Pressing the button to continue. . ."));
  pinMode(buttonPin, INPUT);
  }

void loop() {
  buttonState = digitalRead(buttonPin);
  lightValue = analogRead(lightSensorPin);
  Serial.println(lightValue);
  delay(5);
  // check if pushbutton is pressed
  if (buttonState == HIGH){
    buttonCounter++;
  }
  if (buttonCounter % 2 == 1){ //when button is pressed
      // Netflix and Chill
      Serial.println(F("Netflixing and Chilling. . . :)"));
      // turn on tv
      mySender.send(1474553879); // power tv
      mySender.send(REPEAT_CODE);
      delay(1700);// wait to 
      // turn on lights
      mySender.send(16712445); //power lights
      mySender.send(REPEAT_CODE);
      mySender.send(16734375); //purple light
      mySender.send(REPEAT_CODE);
      delay(1000); //wait to
      // Netflix
      mySender.send(1474513589); //netflix
      mySender.send(REPEAT_CODE);
      buttonCounter++;
  }
  if (buttonCounter >= 1){
    if (lightValue > (goalLightValue+15)){ //is to bright for accecptable range
        mySender.send(16759365); //decrease brightness
        mySender.send(REPEAT_CODE);
        tmp++;
    }
    else if (lightValue < (goalLightValue-15)){//is too dark for acceptable range
        mySender.send(16726725); //increase brightness
        mySender.send(REPEAT_CODE);
        }
    }  
  
    
}
