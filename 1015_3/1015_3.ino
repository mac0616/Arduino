void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
  long du;
  float di;
  digitalWrite(2, 1); //HIgh = 1 = 5v 나옴.
  delayMicroseconds(10);  //10ms는 유지해야 신호가 나옴.
  digitalWrite(2,0);
  du = pulseIn(3,1); //ms(미리세컨즈)로 갔다가 돌아오는 시간 long형으로 측정해줌.
  di = 340.0*du/1000000/2;
  Serial.print(di*100);
  Serial.println(" cm");
  delay(300);
}