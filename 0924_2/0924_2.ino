//온도센서 라이브러리 사용하기 
//[Tools] - [manage3r library] 선택 -> dht11 검색 -> 아무 라이브러리나 사용해도 됨. 수업은 simpleDHT 라이브러리 사용.
// file -> sample -> simpleDHT -> DHT11Default
#include <SimpleDHT.h>

SimpleDHT11 mydht(2);
SimpleDHT11 mydht2(4);

void setup() {
  Serial.begin(115200);

}

void loop() {
  byte t1; //온도
  byte h1; //습도

  byte t2; 
  byte h2;

  mydht.read(&t1, &h1, NULL);
  mydht2.read(&t2, h2, NULL);
  Serial.print("A: ");
  Serial.print(t1);
  Serial.print("B: ");
  Serial.print(h1);
  Serial.println();
  float avg;
  avg = (t1+t2)/2.0;
  //Serial.print(avg);
}
