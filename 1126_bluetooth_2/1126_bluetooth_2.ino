#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);  //RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(7, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    char a = mySerial.read();
    if (a == 'o') {
      digitalWrite(7, 1);
    } else if (a == 'x') {
      digitalWrite(7, 0);
    }
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
