#include <IRLibAll.h>

//create a reciever to listen on digital pin 2 (reciever)
IRrecvPCI myReceiver(2);

//Create a decoder
IRdecode myDecoder;

void setup() {
  Serial.begin(9600);
  delay(2000);
  myReceiver.enableIRIn(); //Start the receiver
  Serial.println(F("Ready to recieve IR signals."));
}

void loop() {
  if(myReceiver.getResults()){
    Serial.println(F("Recieved!"));
    myDecoder.decode(); //decode it
    myDecoder.dumpResults(true); //print results (false is less verbose)
    myReceiver.enableIRIn(); //restart receiver
  }
}
