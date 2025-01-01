void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, INPUT);
}

void loop() {
  long du;
  float di;
  digitalWrite(10, 1);
  delayMicroseconds(10);
  digitalWrite(10, 0);

  du = pulseIn(9, 1);
  di = 340.0 * du / 1000000 / 2;
  Serial.println(di * 100);
  di = di * 100;
  if (di >= 10.0 && di <= 20.0) {
    digitalWrite(7, 1);
  } else if (di >= 30.0 && di <= 40.0) {
    digitalWrite(7, 1);
    digitalWrite(8, 1);
  } else {
    digitalWrite(7, 0);
    digitalWrite(8, 0);
  }
}