#include <LedControl.h>

int DIN = 12;
int CS = 11;
int CLK = 10;

/* Create a new LedControl variable.
 * We use pins 12,11 and 10 on the Arduino for the SPI interface
 * Pin 12 is connected to the DATA IN-pin of the first MAX7221
 * Pin 11 is connected to the CLK-pin of the first MAX7221
 * Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221
 * There will only be a single MAX7221 attached to the arduino 
 */  
 
LedControl lc = LedControl(DIN, CLK, CS, 1);

const int delayMs = 50;
const int delayRowColMs = 500;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 7);
  lc.clearDisplay(0);
}

void loop() {
  AnimateRows();
  AnimateColumns();
  for(int i = 0; i < 16; i++){
    AnimateTopRowL2R();
    AnimateRightColT2B();
    AnimateBottomRowR2L();
    AnimateLeftColB2T();
  }
}

/* 
 *  NOTE: Three mainly used functions
 * lc.setLed(deviceId, row, column, true);
 * lc.setRow(0,rowId,B10000000);
 * lc.setColumn(0,columnId,B10000000);
*/

void AnimateTopRowL2R() {
  for (int i = 0; i < 8; i++) {
    lc.setLed(0, 0, i, true);
    delay(delayMs);
    lc.setLed(0, 0, i, false);
  }
  lc.clearDisplay(0);
}

void AnimateRightColT2B() {
  for (int i = 0; i < 8; i++) {
    lc.setLed(0, i, 7, true);
    delay(delayMs);
    lc.setLed(0, i, 7, false);
  }
  lc.clearDisplay(0);
}

void AnimateBottomRowR2L() {
  for (int i = 7; i >= 0; i--) {
    lc.setLed(0, 7, i, true);
    delay(delayMs);
    lc.setLed(0, 7, i, false);
  }
  lc.clearDisplay(0);
}

void AnimateLeftColB2T() {
  for (int i = 7; i >= 0; i--) {
    lc.setLed(0, i, 0, true);
    delay(delayMs);
    lc.setLed(0, i, 0, false);
  }
  lc.clearDisplay(0);
}


void AnimateRows() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, B11111111);
    delay(delayRowColMs);
    lc.clearDisplay(0);
  }
}

void AnimateColumns() {
  for (int i = 0; i < 8; i++) {
    lc.setColumn(0, i, B11111111);
    delay(delayRowColMs);
    lc.clearDisplay(0);
  }
}
