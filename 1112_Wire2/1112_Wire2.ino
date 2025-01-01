#include <Wire.h >
const int MPU=0x68; //MPU 6050 의 I2C 기본 주소
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

double degY;  // angle Y to deg
double degX; 
double reY; double reX; 

void setup() {
 Wire.begin(); //Wire 라이브러리 초기화
 Wire.beginTransmission(MPU); //MPU로 데이터전송 시작 
 Wire.write(0x6B); // PWR_MGMT_1 register
 Wire.write(0); //MPU-6050 시작 모드로
 Wire.endTransmission(true);
 Serial.begin(9600);
}

void loop() {
 Wire.beginTransmission(MPU); //데이터 전송시작 
 Wire.write(0x3B); //register 0x3B 큐에 데이터 기록 
 Wire.endTransmission(false); //연결유지
 Wire.requestFrom(MPU,14,true); //MPU에 데이터 요청 //14바이트 요청, 다음의 read() 로 한바이트씩 읽어냄.
 AcX=Wire.read()<<8|Wire.read(); // 0x3B:H, 0x3C:L
 AcY=Wire.read()<<8|Wire.read(); // 0x3D:H, 0x3E:L
 AcZ=Wire.read()<<8|Wire.read(); // 0x3F:H, 0x40:L
 Tmp=Wire.read()<<8|Wire.read(); // 0x41:H, 0x42:L
 GyX=Wire.read()<<8|Wire.read(); // 0x43:H, 0x44:L
 GyY=Wire.read()<<8|Wire.read(); // 0x45:H, 0x46:L
 GyZ=Wire.read()<<8|Wire.read(); // 0x47:H, 0x48:L

 degY = atan2(AcX,AcZ) * 180 / PI; // rad to deg
 degX = atan2(AcY,AcZ) * 180 / PI; // rad to deg
 Serial.print("degY : "); Serial.println(degY);
 Serial.print("degX: "); Serial.println(degX); 
 delay(1000);
 Serial.println();
/*
 reY = atan(-AcX / sqrt(pow(AcY, 2) + pow(AcZ, 2))); 
 reY *= 180/PI;
 reX = atan(AcY / sqrt(pow(AcX, 2) + pow(AcZ, 2)));
 reX *= 180/PI;
 Serial.print("reY : "); Serial.println(reY);
 Serial.print("reX: "); Serial.println(reX);
 delay(1000);
 Serial.println();*/
}
