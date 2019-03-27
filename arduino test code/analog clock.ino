#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include "RTClib.h"

int h,m,h12,cmin,prevH,prevM;

RTC_DS1307 rtc;

#define PIN            4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);
void setup () 
{

Serial.begin(9600);
  pixels.begin();
  if (! rtc.begin()) 
  {

    for(int i=0;i<=12;i++){
      pixels.setPixelColor(i,pixels.Color(150,0,0));
      pixels.show();
    }

    while (1);
  }

  if (! rtc.isrunning()) 
  {
 for(int i=0;i<=12;i++){
      pixels.setPixelColor(i,pixels.Color(0,255,0));
      pixels.show();
      delay(200);
    }

  }
for(int i=0;i<=12;i++){
      pixels.setPixelColor(i,pixels.Color(0,0,0));
      pixels.show();
      delay(200);
    }
   
  
}

void loop () 
{
DateTime now = rtc.now();
h = now.hour();
m = now.minute();

h12 = hrs(h);
cmin = mnts(m);
prevH = h12-1;
prevM = cmin-1;

if(prevM!=h12){
  pixels.setPixelColor(prevM,pixels.Color(0,0,0));
  pixels.show();
}

if(prevH!=cmin){
  pixels.setPixelColor(prevH,pixels.Color(0,0,0));
  pixels.show();
}

if(cmin==h12)
{

  pixels.setPixelColor(cmin,pixels.Color(150,0,150));
  pixels.show();
}

if(cmin!=h12)
{
  
pixels.setPixelColor(h12,pixels.Color(0,200,0));
pixels.setPixelColor(cmin,pixels.Color(200,0,0));
pixels.show();
}


















Serial.println("Hour");
Serial.print(h12);
Serial.println("Minute");
Serial.print(cmin);
Serial.println();
}
      
    
    

  



int hrs(int h)
{
  switch(h){
  case 12:
  h = 0;
  break;
  case 13:
  h = 1;
  break;
  case 14:
  h=2;
  case 15:
  h = 3;
  break;
  case 16:
  h = 4;
  break;
  case 17:
  h = 5;
  break;
  case 18:
  h = 6;
  break;
  case 19:
  h = 7;
  break;
  case 20:
  h = 8;
  break;
  case 21:
  h = 9;
  break;
  case 22:
  h = 10;
  break;
  case 23:
  h = 11;
  break;
  case 24:
  h = 0;
  break;
  
}

  return h;
  
}


int mnts(int m){
int c;

if(m==60||m<=4){

c=0;
 }

if(m>=5&&m<=9){
c=1;
 }

if(m>=10&&m<=14){
c=2;
 }

if(m>=15&&m<=19){
c=3;
 }

if(m>=20&&m<=24){
c=4;
 }

if(m>=25&&m<=29){
c=5;
 }

if(m>=30&&m<=34){
c=6;
 }

if(m>=35&&m<=39){
c=7;
 }

if(m>=40&&m<=44){
c=8;
 }

if(m>=45&&m<=49){
c=9;
 }

if(m>=50&&m<=54){
c=10;
 }

if(m>=55&&m<=59){
c=11;
 }
  

return c;

  
}

