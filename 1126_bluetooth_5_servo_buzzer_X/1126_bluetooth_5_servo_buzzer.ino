#include <SoftwareSerial.h>
#include <Servo.h>

#define BUZZER_PIN 8 

const String PASSWORD = "1234"; 


String command = "";
String receivedPassword = "";
SoftwareSerial mySerial(2, 3); 
Servo myServo;

void setup() {
  Serial.begin(9600);     
  mySerial.begin(9600);    
  myServo.attach(9);       
  pinMode(BUZZER_PIN, OUTPUT); 
  myServo.write(0);        
  digitalWrite(BUZZER_PIN, LOW); 
}

void loop() {
  if (mySerial.available()) {
    char received = mySerial.read();
    if (received != '\n') {          
      command += received;          
    } else {
      command.trim();                
      if (command == "open") {       
        mySerial.println("Enter Password:");
        receivedPassword = "";      
        while (true) {
          if (mySerial.available()) {
            char passChar = mySerial.read();
            if (passChar != '\n') { 
              receivedPassword += passChar; 
            } else {
              receivedPassword.trim();
              if (receivedPassword == PASSWORD) { 
                myServo.write(90);               
                delay(1000);                    
                myServo.write(0);               
                mySerial.println("맞는 비밀번호");
                break;                           
              } else {
                mySerial.println("틀린비밀번호");
                buzz(3000);                      
                break;                        
              }
            }
          }
        }
      }
      command = ""; 
    }
  }
}

// 부저 울리기 함수
void buzz(int duration) {
  digitalWrite(BUZZER_PIN, HIGH); 
  delay(duration);                
  digitalWrite(BUZZER_PIN, LOW);  
}
