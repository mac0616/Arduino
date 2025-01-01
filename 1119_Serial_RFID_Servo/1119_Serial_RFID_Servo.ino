#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myServo;
SoftwareSerial mySerial(2,3); // RX, TX

byte authorizedUID[] = {0xFD, 0x55, 0x2D, 0x03};

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(5, OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  myServo.attach(3); 
  myServo.write(0);  
  Serial.println("카드를 리더기에 대세요.");
}

void loop() {
  if(mySerial.available()){
    Serial.write(mySerial.read());
  }
  if(Serial.available()){
    mySerial.write(Serial.read());
  }

  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // UID 검사
  if (checkUID(mfrc522.uid.uidByte, mfrc522.uid.size)) {
    Serial.println("인증된 카드");
    myServo.write(90);  
    delay(1000);       
    myServo.write(0);   
    delay(1000);        
  } else {
    Serial.println("인증되지 않은 카드입니다.");
  }

  mfrc522.PICC_HaltA(); 
}

bool checkUID(byte *uid, byte uidSize) {
  if (uidSize != sizeof(authorizedUID)) {
    return false;
  }
  
  for (byte i = 0; i < uidSize; i++) {
    if (uid[i] != authorizedUID[i]) {
      return false;
    }
  }
  return true;
}
