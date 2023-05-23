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
}

void loop()
{
  String  temp;

  temp=String((analogRead(A0)*(5.00/1024))/0.01);

  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(1000);
  lcd.clear();
}

