#include <LCD_I2C.h>
#include <SimpleDHT.h>

LCD_I2C lcd(0x27, 16, 2); 
SimpleDHT11 mydht(2);

void setup()
{
    lcd.begin(); 
    lcd.backlight();
}

void loop()
{
    byte t1; //온도
    byte h1; //습도
    mydht.read(&t1, &h1, NULL);
    
    lcd.print("Temp. = ");
    lcd.print(t1);
    lcd.print("C");
    lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
    lcd.print("Humi. = " );
    lcd.print(h1);
    lcd.print("%");
    delay(1000);

    // Flashing the backlight
    for (int i = 0; i < 5; ++i)
    {
        lcd.backlight();
        delay(50);
        lcd.noBacklight();
        delay(50);
    }

    lcd.backlight();
    lcd.clear();
    delay(1000);
}
