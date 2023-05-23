#define BLYNK_TEMPLATE_ID "TMPL3J4dk-EG0"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "9OW7kn1IbktT8sGuVrZDZqG_2y7cvSb5"

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

#define LED 2

char auth[]=BLYNK_AUTH_TOKEN;

BLYNK_WRITE(V0)
{
  int value = param.asInt();

  if(value)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
}


void setup() 
{
  Blynk.begin(auth);
  pinMode(LED,OUTPUT);
}

void loop() 
{
  Blynk.run();
}
