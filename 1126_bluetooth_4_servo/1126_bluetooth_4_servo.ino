#include <SoftwareSerial.h>
#include <Servo.h>

String state = "";
SoftwareSerial mySerial(2, 3); 
Servo myServo;

void setup() {
  Serial.begin(9600);      
  mySerial.begin(9600);    
  myServo.attach(9);     
  myServo.write(0);        
}

void loop() {
  // Bluetooth로 받은 데이터 읽기
  if (mySerial.available()) {
    char received = mySerial.read(); 
    if (received != '\n') {       
      state += received;            
    } else {
      state.trim();                 
      if (state == "open") {         
        myServo.write(90);          
        delay(1000);                 
        myServo.write(0);            
        Serial.println("Good");
      } else {
        myServo.write(0);            
        Serial.println("No");
      }
      state = ""; 
    }
  }

  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
