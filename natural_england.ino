
// ThingPulse SSD1306 library
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

#include "ex.h"
#include "mation.h"
#include "puke.h"
#include "trash.h"
#include "SSD1306Spi.h"
#include "SH1106Spi.h"
// ------------------begin ESP8266'centric----------------------------------
#define FREQUENCY    160                  // valid 80, 160
//
#include "ESP8266WiFi.h"

// ------------------end ESP8266'centric------------------------------------
SSD1306Spi        display(D0, D2, 18);
//SH1106Spi       display(D0, D2, 18);

uint8_t i = 0;
uint8_t j = 0;
uint8_t k = 0;
uint8_t l = 0;
void setup() {
  /* Initializations */
  // ------------------begin ESP8266'centric----------------------------------
  WiFi.forceSleepBegin();                  // turn off ESP8266 RF

  // ------------------end ESP8266'centric------------------------------------
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(D8, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D1, OUTPUT);

  digitalWrite(D8, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D1, LOW);


  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.init();
  // init done
  digitalWrite(D1, HIGH);
//  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  //
  
  display.flipScreenVertically();
  digitalWrite(D3, HIGH);

  display.invertDisplay();
  digitalWrite(D8, HIGH);






}

void loop() {
  display.clear();

  //block one
  digitalWrite(D8, LOW);
  display.drawRect(127, 63, 1, 1);
  display.drawXbm( 0, 0, 128, 64, ex[i]);
  display.display();
  digitalWrite(D8, HIGH);

  if (i == 49) {
    i = 0;
  } else {
    i++;
  }
  display.clear();



  //block two
  digitalWrite(D4, LOW);
  display.drawRect(0, 0, 1, 1);
  display.drawXbm(0 , 0, 128, 64, puke[j]);
  display.display();
  digitalWrite(D4, HIGH);

  if (j == 23) {
    j = 0;
  } else {
    j++;
  }
  display.clear();

   //block four
  digitalWrite(D3, LOW);
  display.drawRect(0, 0, 1, 1);
  display.drawRect(128, 128, 1, 1);
  display.drawXbm(0 , 0, 128, 64, trash[l]);
  display.display();
  digitalWrite(D3, HIGH);

  if (l == 45) {
    l = 0;
  } else {
    l++;
  }
  display.clear();
  
  //block three
  digitalWrite(D1, LOW);
  display.drawRect(128, 128, 1, 1);
  display.drawXbm(0 , 0, 128, 64, mation[k]);
  display.display();
  digitalWrite(D1, HIGH);

  if (k == 30) {
    k = 0;
  } else {
    k++;
  }

  display.clear();

 
  delay(50);

  //
}
