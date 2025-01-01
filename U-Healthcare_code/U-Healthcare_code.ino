#include "DHT.h" 
DHT dht(10, DHT22); 
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define no_dust 0.60 

int dustout=A4;

int v_led=A5;
int s_ledr=13; // 나쁨 RED
int s_ledg=12; // 보통 Green
int s_ledb=11; // 좋음 Blue
float vo_value=0; 
float sensor_voltage=0; 
float dust_density=0; // 실제 미세먼지 밀도

 void setup()
{
 Serial.begin(9600); 
 dht.begin();
 pinMode(v_led,OUTPUT); 
 pinMode(s_ledr,OUTPUT); 
 pinMode(s_ledg,OUTPUT); 
 pinMode(s_ledb,OUTPUT); 
 lcd.begin(16, 2);   
 lcd.setCursor(0,0);
 lcd.clear();
 digitalWrite(v_led,LOW); 
 digitalWrite(s_ledr,LOW);
 digitalWrite(s_ledb,LOW);
 digitalWrite(s_ledg,LOW);
}
void loop()
{
 digitalWrite(v_led,LOW); 
 delayMicroseconds(280); 
 vo_value=analogRead(dustout);
 delayMicroseconds(40); 
 digitalWrite(v_led,HIGH); 
 delayMicroseconds(9680); 
 lcd.clear();
 sensor_voltage=get_voltage(vo_value); 
 dust_density=get_dust_density(sensor_voltage);
   int dust_density1 = dust_density;
   
   Serial.print(dust_density1);
   Serial.println(" [ug/m^3]");
   lcd.setCursor(0, 1);
   lcd.print("Dust:"); 
   lcd.setCursor(5, 1);
   lcd.print(dust_density1);
   lcd.setCursor(8, 1);
   lcd.print("[ug/m^3]");
   Serial.print("value = ");
   Serial.println(vo_value);
   Serial.print("Voltage = ");
   Serial.print(sensor_voltage);
   Serial.println(" [V]");
   Serial.print("Dust Density = ");
   Serial.print(dust_density);
   Serial.println(" [ug/m^3]");
   float h = dht.readHumidity();
   float t = dht.readTemperature(); 
   float f = dht.readTemperature(true);
   float hif = dht.computeHeatIndex(f, h);
   float hic = dht.computeHeatIndex(t, h, false);
   int hic1=hic;
   int h1=h;
   
   Serial.print("Temperature: ");
   Serial.print(hic); 
   Serial.println("C");
   lcd.setCursor(0, 0);
   lcd.print("temp:");
   lcd.setCursor(5, 0);
   lcd.print(hic1);
   lcd.setCursor(7, 0);
   lcd.print("C ");
   
   Serial.print("Humidity: "); 
   Serial.print(h); 
   Serial.println("%");
   lcd.setCursor(9, 0);
   lcd.print("Hum:");
   lcd.setCursor(13, 0);
   lcd.print(h1);
   lcd.setCursor(15, 0);
   lcd.print("%");
   
  
   

   if(dust_density <= 50){
    digitalWrite(s_ledr,LOW);
    digitalWrite(s_ledb,HIGH);
    digitalWrite(s_ledg,LOW);
    Serial.println("LED B");
   }
   else if(dust_density <= 100){
    digitalWrite(s_ledr,LOW);
    digitalWrite(s_ledb,LOW);
    digitalWrite(s_ledg,HIGH) ;
    Serial.println("LED G");
   }
   else {
    digitalWrite(s_ledr,HIGH);
    digitalWrite(s_ledb,LOW);
    digitalWrite(s_ledg,LOW);
    Serial.println("LED R");
   }
   delay(2000);
}


float get_voltage(float value)
{
 float V= value * 5.0 / 1024; 
 return V;
}

float get_dust_density(float voltage)
{
 float dust=(voltage-no_dust) / 0.005; 
}
