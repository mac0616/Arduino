#include <SoftwareSerial.h>
#include <SimpleDHT.h>

SoftwareSerial mySerial(2, 3);  //RX, TX
SimpleDHT11 mydht(7);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  byte t1, h1;  //온도
  mydht.read(&t1, &h1, NULL);
  mySerial.println(t1);
  delay(1000);
  /*
  if (mySerial.available()) {
    Serial.write(mySerial.read());
    //delay(1000);
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }*/
}
