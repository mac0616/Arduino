#include <SoftwareSerial.h>
#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);
SoftwareSerial mySerial(2,3); //시리얼통신 핀

byte authorizedUID[] = {0xFD, 0x55, 0x2D, 0x03};

void setup()
{
  mySerial.begin(9600); //기존 9600이여서 다른 통신속도를 사용해야함
  mfrc522.PCD_Init();
  Serial.println("카드를 리더기에 대세요.");
}

void loop()
{
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  mySerial.write('1'); // 2번 아두이노에 '1'값 전송
  delay(1000);
  
  mySerial.write('0');  // 2번 아두이노에 '1'값 전송
  delay(1000);
}