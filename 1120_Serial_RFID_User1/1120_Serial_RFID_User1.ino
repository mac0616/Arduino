#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID 모듈 설정
byte card1UID[] = {0xF5, 0xEC, 0x26, 0x03}; // 카드 1 UID(채연)
byte card2UID[] = {0xFD, 0x55, 0x2D, 0x03}; // 카드 2 UID(주은)
SoftwareSerial mySerial(2, 3); // RX, TX (아두이노 B와 통신)

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init(); // RFID 초기화
  mySerial.begin(9600); // SoftwareSerial 초기화
  Serial.println("카드를 리더기에 대세요.");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return; // 새 카드가 없거나 읽을 수 없을 경우
  }

  // UID 검사
  if (checkUID(mfrc522.uid.uidByte, mfrc522.uid.size, card1UID)) {
    Serial.println("카드가 인식되었습니다.");
    mySerial.write('a'); // 카드 1일 경우 'a' 전송
  } else if (checkUID(mfrc522.uid.uidByte, mfrc522.uid.size, card2UID)) {
    Serial.println("특정카드가 인식되었습니다.");
    mySerial.write('b'); // 카드 2일 경우 'b' 전송
  } else {
    Serial.println("인증되지 않은 카드입니다.");
    mySerial.write('n'); // 인증되지 않은 카드일 경우 'n' 전송
  }

  mfrc522.PICC_HaltA(); // 카드 동작 중지
}

bool checkUID(byte *uid, byte uidSize, byte *targetUID) {
  for (byte i = 0; i < uidSize; i++) {
    if (uid[i] != targetUID[i]) {
      return false; // UID 불일치
    }
  }
  return true; // UID 일치
}