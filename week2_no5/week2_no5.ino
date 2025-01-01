int i;

void setup() {
  Serial.begin(9600); //9600bps(bps=bits per second)
  i=5;
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println(i);
  i=i-1;
  delay(1000);
  if(i<0){
    i=5;
    digitalWrite(13,1);
    delay(2000);
    digitalWrite(13,0);
  }
}
