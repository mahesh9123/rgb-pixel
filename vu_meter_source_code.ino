//Develop by creative KHOPDI


//NOTE:-ADJUST/SET BY POTENTIOMETER OF SOUND SENSOR IF LESS NUMBER OF PATTERN OBSERVE

#include <FastLED.h>

int r=152;
int g=0;
int b=10;

#define LED_PIN     5            //CONNECT DATA PIN OF PIXEL WITH 5 NUMBER PIN OF ARDUINO
#define NUM_LEDS    30           //CHANGE THE VALUE IF YOU WANT TO USE DIFFRENT NUMBER OF LED IN YOUR STRIP,HERE IN MY STRIP NUMBER OF LED IS 30 SO I SET IT 30.

CRGB leds[NUM_LEDS];
CRGB led[NUM_LEDS];
CRGB led_bucket[NUM_LEDS];
int s=0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for (int i = NUM_LEDS; i >= 0; i--) 
  {
     led_bucket[NUM_LEDS-i] = CRGB (r,g,b );
     delay(40);
    FastLED.show();
  }
  Serial.begin(9600);
   pinMode(A0,INPUT);

}
void loop()
{
  s=analogRead(A0);
  s=s*2;
//  Serial.println(s);
//  delay(50);
  if((s>=450)&&(s<=550))
  {
    led_bucket[0]=CRGB (0, 0, 255);
    led_bucket[1]=CRGB (0, 0, 255);
  }
  else if((s>=400)&&(s<=450))
  {
    led_bucket[0]=CRGB (153, 153, 0);
    led_bucket[1]=CRGB (153, 153, 0);
  }
  else if((s>=350)&&(s<=400))
   {
     led_bucket[0]=CRGB (255, 50, 255);
    led_bucket[1]=CRGB (255, 50, 255);
   }
   else if((s>=300)&&(s<=350))
  {
    led_bucket[0]=CRGB (10, 25, 217);
    led_bucket[1]=CRGB (10, 25, 217);
  }

    else if((s>=276)&&(s<=300))
   {
     led_bucket[0]=CRGB (50, 50, 150);
    led_bucket[1]=CRGB (50, 50, 150);
   }
   else if((s>=250)&&(s<=275))
   {
     led_bucket[0]=CRGB (230, 0, 10);
    led_bucket[1]=CRGB (230, 0, 10);
   }
  else if((s>=235)&&(s<=250))
   {
     led_bucket[0]=CRGB (0, 160, 0);
    led_bucket[1]=CRGB (0, 160, 0);
   }
   else if((s>=200)&&(s<=230))
   {
     led_bucket[0]=CRGB (1, 0, 1);
    led_bucket[1]=CRGB (1, 0, 1);
   }
  else
  {
     led_bucket[0] = CRGB ( r,s-100,b);
     led_bucket[1] = CRGB ( r,s-100,b);
  }
    for (int i = 0; i <= (NUM_LEDS-2); i++) 
  {
      led_bucket[NUM_LEDS-1-i] = led_bucket[(NUM_LEDS)-i-2];
      leds[NUM_LEDS-1-i] = led_bucket[(NUM_LEDS)-i-2];        
  }
  if(s>=450)
  {
    s=450;
  }
    if(s<=100)
  {
    s=100;
  }
    for (int i = (450-s)/15; i >=0; i--) 
  {
      leds[NUM_LEDS-i] = CRGB (0, 0, 0);          
  }
 FastLED.show();
 delay(25);

}
