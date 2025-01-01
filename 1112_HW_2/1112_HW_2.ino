#include <MPU6050_tockn.h>
#include <Wire.h>

Serial myPort;

float x=0;
float y=0;
float z=0;

void setup() {
    println(Serial.list());
    myPort = new Serial(this, Serial.list()[0], 9600);
    myPort.bufferUntil('\n');
    noStroke();
    size(600,600,P3D);    
} 

void draw() {  
    background(0); //배경색
    lights();  //조명

    pushMatrix();  //Start
    fill(0,255,0); //채우기
    translate(width/2,height/2,-100); //이동
    rotateX(radians(y)); //x축 회전
    rotateY(radians(x)); //y축 회전
    rotateZ(radians(z)); //y축 회전
    
    box(200,100,200); //상자
    popMatrix(); //End
}
 
void serialEvent(Serial p) { 
  String inString = myPort.readStringUntil('\n');   
  int separator_ch = inString.indexOf(",");
  if(separator_ch!=-1){
    String[] inStrings = split(inString, ',');
    x=float(inStrings[0]);
    y=float(inStrings[1]);
    z=float(inStrings[2]);
  
    print(x);
    print('/');
    print(y);
    print('/');
    println(z);
  }else{
    print(inString);
  }
}