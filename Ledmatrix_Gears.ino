#include <LedControl.h>

int DIN = 7;
int CS =  6;
int CLK = 5;

byte neutral[8]= {0xe7,0xf7,0xf7,0xff,0xff,0xef,0xef,0xe7};
byte reverse[8] = {0xff,0xff,0xe7,0xfc,0xfc,0xe7,0xe7,0xe7};
byte one[8] = {0x1c,0x3c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c};
byte two[8]= {0x7e,0xff,0xe7,0xe,0x38,0xe0,0xff,0xff};
byte three[8]= {0xfe,0xff,0x7,0xff,0xff,0x7,0xff,0xfe};
byte four[8]= {0xee,0xee,0xee,0xff,0xff,0xe,0xe,0xe};
byte five[8] = {0xff,0xff,0xe0,0xff,0xff,0x7,0xff,0xff};
byte six[8] = {0xff,0xff,0xe0,0xff,0xff,0xe7,0xff,0xff};
byte seven[8] = {0xff,0xff,0xff,0x7,0x7,0x7,0x7,0x7};
byte eight[8] = {0x7e,0xff,0xe7,0xff,0xff,0xe7,0xff,0x7e};

LedControl lc=LedControl(DIN,CLK,CS,1);

void setup(){
 lc.shutdown(0,false);       
 lc.setIntensity(0,5);
 lc.clearDisplay(0);
}

void loop()
{ 
   printByte(neutral);     
   delay(1000);

   printByte(reverse);     
   delay(1000);

   printByte(one);     
   delay(1000);
    
   printByte(two);     
   delay(1000);

   printByte(three);     
   delay(1000);

   printByte(four);     
   delay(1000);

   printByte(five);     
   delay(1000);

   printByte(six);     
   delay(1000);

   printByte(seven);     
   delay(1000);

   printByte(eight);     
   delay(1000);
    
   lc.clearDisplay(0);
   delay(1000);
}


void printByte(byte character [])
{
  int i = 0;
  for(i = 0; i < 8; i++)
  {
    lc.setRow( 0, i, character[i]);
  }
}
