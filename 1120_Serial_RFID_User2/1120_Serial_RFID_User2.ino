#include <SoftwareSerial.h>
#include <Servo.h>

char state; // 수신된 데이터 저장
SoftwareSerial mySerial(2, 3); // RX, TX (아두이노 A와 통신)
Servo myServo;

void setup() {
  Serial.begin(9600); // 디버그 출력용
  mySerial.begin(9600); // SoftwareSerial 초기화
  pinMode(7, OUTPUT); // LED 핀 설정
  myServo.attach(9);
  myServo.write(0);// 초기 위치
}

void loop() {
  if (mySerial.available() > 0) { // 데이터가 수신되었는지 확인
    state = mySerial.read(); // 수신된 데이터를 읽어서 state에 저장

    if (state == 'a') { // 수신 데이터가 'y'이면
      Serial. println("LED ON");
      digitalWrite(7, HIGH); // LED ON
      delay(1000); // 1초 대기
      digitalWrite(7, LOW); // LED OFF
    }
    else if (state == 'b'){
      Serial.println("서보 모터 작동");
      myServo.write(90);
      delay(1000);
      myServo.write(0);
    }
    else{
      Serial.println("GET OUT");
    }

    Serial.println(state); // 수신된 데이터 출력
  }
}
