#include <Arduino.h>
#include <FastLED.h>
#include <M5_PbHub.h>





#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BROCHE_ATOM_BTN 39
#define BROCHE_ATOM_LUMIERE 27
#define CANAL_0 0

// CRGB keyPixel;
CRGB keyPixel2;
M5_PbHub myPbHub;


void setup()
{

  Wire.begin();
  myPbHub.begin();
  myPbHub.setPixelCount( CANAL_0 ,  1 );



  // Initialiser FastLED pour contrôler le pixel RGB du M5Stack Key Unit
  // FastLED.addLeds<WS2812, BROCHE_ATOM_FIL_JAUNE, GRB>(&keyPixel, 1);
  FastLED.addLeds<WS2812, BROCHE_ATOM_LUMIERE, GRB>(&keyPixel2, 1);

  // pinMode(BROCHE_ATOM_FIL_BLANC, INPUT_PULLUP);
  pinMode(BROCHE_ATOM_BTN, INPUT_PULLUP);
}

void loop()
{
  // put your main code here, to run repeatedly:

  // int maLectureKey = digitalRead(BROCHE_ATOM_FIL_BLANC);

  int maLectureBtn = digitalRead(BROCHE_ATOM_BTN);
  int value = myPbHub.digitalRead(CANAL_0);


  // if (maLectureKey == 0)
  // {

  //   keyPixel = CRGB(220, 255, 0); // BLANC
  // }
  // else
  // {

  //   keyPixel = CRGB(0, 0, 0); // BLANC
  // }


  if (maLectureBtn == 0)
  {

    keyPixel2 = CRGB(220, 0, 150); // BLANC

  }
  else
  {

    keyPixel2 = CRGB(0, 0, 0); // BLANC

  }


  // TOUCHE DE CLAVIER
  
  if (value == 0)
  {

    myPbHub.setPixelColor(CANAL_0, 0, 220,0, 150);

  }
  else
  {

    myPbHub.setPixelColor(CANAL_0, 0, 0,0, 0);

  }


  FastLED.show();

  delay(20);
}
