#include <LCD_I2C.h>
#include <SimpleDHT.h>

LCD_I2C lcd(0x27, 16, 2);
SimpleDHT11 mydht(2);
SimpleDHT11 mydht2(3);

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  byte t1, t2, h1, h2;
  mydht.read(&t1, &h1, NULL);
  mydht2.read(&t2, &h2, NULL);

  float avg;
  avg = (h1 + h2) / 2.0;
  lcd.print("h1 = ");
  lcd.print(h1);
  lcd.print(" h2 = ");
  lcd.print(h2);
  lcd.setCursor(0, 1);
  lcd.print("avg = ");
  lcd.print(avg);
  delay(1000);

  lcd.backlight();
  lcd.clear();
  delay(50);
}
