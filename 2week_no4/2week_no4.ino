// C++ code
//
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  /* 4-1
  digitalWrite(9, 1); 
  digitalWrite(8, 1);
  delay(1000);
  digitalWrite(7, 1); 
  digitalWrite(8, 0);
  delay(1000);
  digitalWrite(9, 0); 
  digitalWrite(8, 1);
  delay(1000);
  digitalWrite(7, 0);
  */
  digitalWrite(9, 1); 
  digitalWrite(8, 1);
  digitalWrite(7, 1);
  delay(1000);
  digitalWrite(7, 0); 
  delay(1000);
  digitalWrite(8, 0); 
  digitalWrite(7, 1);
  delay(1000);
  digitalWrite(7, 0);
  delay(1000);
  digitalWrite(9, 0); 
  digitalWrite(8, 1);
  digitalWrite(7, 1); 
  delay(1000);
  digitalWrite(7, 0);
  delay(1000);
  digitalWrite(8, 0);
  digitalWrite(7, 1); 
  delay(1000);
  digitalWrite(7, 0);
  delay(1000);
}