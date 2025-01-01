#include <SPI.h>                                                            mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#include <MFRC522.h>
#include <SoftwareSerial.h>
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid(SS_PIN, RST_PIN);
SoftwareSerial mySerial(2,3); 

byte authorizedCard[] = {0xFD, 0x55, 0x2D, 0x03}; // 특정 카드의 UID (4 바이트)
const byte UID_SIZE = sizeof(authorizedCard);

void setup() {
  Serial.begin(9600); // 시리얼 통신 설정
  SPI.begin();        // SPI 초기화
  rfid.PCD_Init();    // RFID 리더 초기화
  Serial.println("RFID Reader Ready");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return; // 새 카드가 없으면 대기
  }

  // UID 비교
  bool isAuthorized = true;
  if (rfid.uid.size == UID_SIZE) { // UID 크기가 일치해야 비교 가능
    for (byte i = 0; i < UID_SIZE; i++) {
      if (rfid.uid.uidByte[i] != authorizedCard[i]) {
        isAuthorized = false;
        break;
      }
    }
  } else {
    isAuthorized = false;
  }

  // 결과 전송
  if (isAuthorized) {
    Serial.println("AUTHORIZED"); // 특정 카드에 대한 신호
  } else {
    Serial.println("DETECTED");   // 일반 카드에 대한 신호
  }

  rfid.PICC_HaltA(); // 카드 읽기 종료
}
