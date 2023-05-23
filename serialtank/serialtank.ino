#define INLET_VALVE  0x00
#define OUTLET_VALVE 0x01

#define HIGH_FLOAT 0x10
#define LOW_FLOAT  0x11

#define VOLUME 0x30

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
unsigned int Value_H,Value_L;
unsigned int vol;
unsigned char volumeL,volumeH;

void setup() 
{
  Serial.begin(19200);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.home();

  lcd.setCursor(0,0);
  lcd.print("Connect Srtank");
  lcd.clear();

  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

void filling_start(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(0x01);

  Serial.write(OUTLET_VALVE);
  Serial.write(0x00);

  lcd.setCursor(0,0);
  lcd.print("Filling");

  do
  {
    Serial.write(HIGH_FLOAT);
    while(!Serial.available());
    Value_H=Serial.read();
    volume();
  }while(Value_H==0);
}

void volume(void)
{
  Serial.write(VOLUME);

  while(!Serial.available());
  volumeH=Serial.read();
  while(!Serial.available());
  volumeL=Serial.read();

  vol = volumeH<<8 | volumeL;

  lcd.setCursor(0,0);
  lcd.print("Volume");
  lcd.print(vol);
  lcd.print("L");
}

void start_emptying(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(0x00);

  Serial.write(OUTLET_VALVE);
  Serial.write(0x01);

  lcd.setCursor(0,0);
  lcd.print("Emptying");

  do
  {
    Serial.write(LOW_FLOAT);
    while(!Serial.available());
    Value_L=Serial.read();
    volume();
  }while(Value_L==1);
}

void loop() 
{
  filling_start();
  start_emptying();
}
