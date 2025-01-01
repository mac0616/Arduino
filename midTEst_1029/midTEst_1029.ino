void setup() {                                                                                                                 
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(9,INPUT);
}

void loop() {
  long du; float dl;
  digitalWrite(10,1);
  delayMicroseconds(10);
  digitalWrite(10, 0);

  du = pulseIn(9, 1);
  dl= 340.0*du/2/100000;

  Serial.println(dl*100);
  dl=dl*100;
  if (dl<=10 && dl>=20){
    digitalWrite(7,1);
  } else if(dl<=30 && dl>=40){
    digitalWrite(7, 1);
    digitalWrite(8, 1);
  } else{
    digitalWrite(7, 0);
    digitalWrite(8, 0);
  }
}
