int i;

void setup() {
  pinMode(3, OUTPUT);
  i=0;

}

void loop() {
  // 1번
  /*digitalWrite(3, 1);
  delay(1000);O
  digitalWrite(3, 0);
  delay(1000);*/
  /*
  analogWrite(3, 225);
  delay(5);
  */
  
  i=i+1;
  if (i>255) i=0;
  analogWrite(3, i);
  delay(20);

}
