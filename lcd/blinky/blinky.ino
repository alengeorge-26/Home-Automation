#define LED 3

void setup() 
{ 
  pinMode(LED,OUTPUT);
}

unsigned int ldr_val;

void loop() 
{
  ldr_val=analogRead(A0);

  ldr_val=(1023-ldr_val)/4;

  analogWrite(LED,ldr_val);

  delay(100);
}
