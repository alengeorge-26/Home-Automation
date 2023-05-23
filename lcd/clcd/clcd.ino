#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  lcd.init();

  lcd.backlight();

  lcd.clear();

  lcd.home();

  lcd.setCursor(0,0);
  lcd.print("HELLO");

  lcd.setCursor(4,1);
  lcd.print("WORLD");
}

void loop()
{

}
