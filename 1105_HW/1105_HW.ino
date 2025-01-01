//.카드 번호확인하기
 /*
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("카드를 리더기에 대세요.");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  Serial.print("카드 UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  mfrc522.PICC_HaltA();
} */

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo m;

byte CardUID[] = {0xF5, 0xEC, 0x26, 0x03}; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  m.attach(3); 
  m.write(0);  
  Serial.println("카드를 리더기에 대세요.");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // UID 검사
  if (checkUID(mfrc522.uid.uidByte, mfrc522.uid.size)) {
    Serial.println("내 카드가 맞습니다.");
    m.write(0);
    delay(100);
    m.write(90);
    delay(100);
    m.write(180);
    delay(100);      
  } else {
    Serial.println("내 카드가 아닙니다.");
  }

  mfrc522.PICC_HaltA(); 
}

bool checkUID(byte *uid, byte uidSize) {
  if (uidSize != sizeof(CardUID)) {
    return false;
  }
  
  for (byte i = 0; i < uidSize; i++) {
    if (uid[i] != CardUID[i]) {
      return false;
    }
  }
  return true;
}