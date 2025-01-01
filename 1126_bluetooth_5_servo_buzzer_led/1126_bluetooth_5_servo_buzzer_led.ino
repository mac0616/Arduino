#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(2, 3); // RX, TX (블루투스 모듈 연결)
Servo myServo;                // 서보 모터 객체 생성

const String password = "0099"; // 설정된 비밀번호

void setup() {
  mySerial.begin(9600);        // 블루투스 시리얼 통신 시작
  myServo.attach(9);           // 서보 모터 핀 연결
  myServo.write(0);            // 서보 모터 초기 위치 설정
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  mySerial.println("Enter the open: ");
}

void loop() {
  if (mySerial.available()) { // 블루투스에서 데이터 수신
    String command = mySerial.readStringUntil('\n'); // 개행문자까지 읽기
    command.trim(); // 불필요한 공백 제거

    if (command.equalsIgnoreCase("open")) { // "open" 명령어 감지
      mySerial.println("Password? "); // 비밀번호 요청 메시지 전송

      // 비밀번호 입력 대기 (사용자가 비밀번호를 입력할 때까지 기다림)
      String inputPassword = "";
      while (inputPassword == "") {  // 입력이 없을 때까지 반복
        if (mySerial.available()) {
          inputPassword = mySerial.readStringUntil('\n'); // 개행문자까지 읽기
          inputPassword.trim(); // 불필요한 공백 제거
        }
      }

      // 비밀번호 확인
      if (inputPassword == password) {
        mySerial.println("Correct!!");
        myServo.write(90);    // 서보 모터를 90도 위치로 이동
        digitalWrite(7, 1);
        delay(1000);          // 1초 대기
        myServo.write(0);     // 서보 모터를 원위치로 이동
        digitalWrite(7,0);
      } else { // 비밀번호가 틀린 경우
        mySerial.println("Wrong Password!!!!!");
        tone(8,500,3000);  // 부저 울리기
        digitalWrite(6, 1);
        delay(3 000);          // 1초 대기
        digitalWrite(6, 0);
      }
    }
  }
}
