void setup() {
  pinMode(10,OUTPUT); // on/off         //stby
  pinMode(6,OUTPUT); // 속도            //pwma
  pinMode(9,OUTPUT); //시계방향 앞으로  //ain1
  pinMode(8,OUTPUT); //반시계 뒤로      //ain2
  pinMode(11,OUTPUT);                  //bin1
  pinMode(12,OUTPUT);                  //bin2
  pinMode(5,OUTPUT);                   //pwmb
}
void loop() {
  digitalWrite(10,1);
  digitalWrite(9,1);
  digitalWrite(8,0);
  analogWrite(6,76);
  digitalWrite(11,1);
  digitalWrite(12,0);
  analogWrite(5,76);

}