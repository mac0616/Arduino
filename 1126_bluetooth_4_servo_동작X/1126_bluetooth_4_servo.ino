#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(2, 3); // RX, TX
Servo m;
String receivedString = "";  // 수신된 문자열을 저장할 변수

void setup() {
  Serial.begin(9600);  // 기본 시리얼 포트 시작
  mySerial.begin(9600);  // 소프트웨어 시리얼 포트 시작
  m.attach(9);
}

void loop() {
  
  // 소프트웨어 시리얼에서 데이터가 수신되었는지 확인
  if (mySerial.available()) {
    char receivedChar = mySerial.read();  // 1바이트씩 읽음

    // 수신된 문자를 문자열에 추가
    receivedString += receivedChar;

    // "Open" 문자열을 완전히 받았다면
    if (receivedString == "open") {
      Serial.println("open command received");  // 디버깅 메시지

      // 서보 모터를 90도로 회전
      m.write(90);  
      delay(1000);  // 1초 동안 대기

      // 서보 모터를 원위치인 0도로 돌아가게 함
      m.write(0);
      delay(1000);  // 1초 대기
      // 명령을 처리한 후 수신된 문자열 초기화
      receivedString = "";
    }
  }

  // 기본 시리얼로 받은 데이터를 소프트웨어 시리얼로 전달
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
