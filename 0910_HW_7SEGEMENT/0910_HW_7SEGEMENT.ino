void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  // 0
  digitalWrite(1, 1);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(1000);
  digitalWrite(1, 0);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(1000);
  //1
  digitalWrite(2, 1);
  digitalWrite(5, 1);
  delay(1000);
  digitalWrite(2, 0);
  digitalWrite(5, 0);
}