// 1
/*
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello");
  delay(1000);
}
*/

//2
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if(Serial.available()){
    int a=Serial.read();
    if(a=='y'){
      digitalWrite(13, 1);
      delay(500);
      digitalWrite(13, 0);
    }
  }
  Serial.println("Hello");
  delay(1000);
}

