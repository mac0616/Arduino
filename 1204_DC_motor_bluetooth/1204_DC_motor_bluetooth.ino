#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX (핀 2), TX (핀 3)

void setup() {
  Serial.begin(9600);

  // 핀 모드 설정
  pinMode(10, OUTPUT); // STBY 핀
  pinMode(6, OUTPUT);  // 왼쪽 모터 속도 제어 (PWM 핀)
  pinMode(5, OUTPUT);  // 오른쪽 모터 속도 제어 (PWM 핀)
  pinMode(8, OUTPUT);  // 왼쪽 모터 반시계 방향
  pinMode(9, OUTPUT);  // 왼쪽 모터 시계 방향
  pinMode(11, OUTPUT); // 오른쪽 모터 시계 방향
  pinMode(12, OUTPUT); // 오른쪽 모터 반시계 방향

  bluetooth.begin(9600);  // 블루투스 통신 시작
  digitalWrite(10, HIGH); // STBY 활성화
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read(); // Bluetooth로부터 명령어 읽기
    Serial.print("Received Command: ");
    Serial.println(command);  // 디버그용 출력

    switch (command) {
      case 'f': // 앞으로
        Serial.println("Forward");
        digitalWrite(9, 1);   
        digitalWrite(8, 0);
        analogWrite(6, 100);

        digitalWrite(11, 1);  
        digitalWrite(12, 0);  
        analogWrite(5, 100);
        break;

      case 'b': // 정지
        Serial.println("Stop");
        digitalWrite(9, 0);   
        digitalWrite(8, 1);
        analogWrite(6, 100);

        digitalWrite(11, 0);   
        digitalWrite(12, 1);  
        analogWrite(5, 100);
        break;

      case 'l': // 왼쪽 회전
        Serial.println("Turn Left");
        digitalWrite(9, 1);   
        digitalWrite(8, 0);
        analogWrite(6, 50);

        digitalWrite(11, 1);   
        digitalWrite(12, 0);  
        analogWrite(5, 100);
        break;

       case 's': // stop
        Serial.println("Stop");
        digitalWrite(9, 0);   
        digitalWrite(8, 0);
        analogWrite(6, 80);

        digitalWrite(11, 0);   
        digitalWrite(12, 0);  
        analogWrite(5, 50);
        break;

      case 'r': // 오른쪽 회전
        Serial.println("Turn Right");
        digitalWrite(9, 1);   
        digitalWrite(8, 0);
        analogWrite(6, 100);

        digitalWrite(11, 1);   
        digitalWrite(12, 0);  
        analogWrite(5, 50);
        break;

      default:
        Serial.println("Unknown Command");
        break;
    }
  }
}
