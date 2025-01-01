void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    int k = Serial.read();
    Serial.println(k);
  }
}

//https://doools.tistory.com/61
//아두이노  핀 배열 설명