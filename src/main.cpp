#include <Arduino.h>
#include <FastLED.h>
#include <M5_PbHub.h>
#include <MicroOscSlip.h>





MicroOscSlip<128> monOsc(&Serial);


#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BROCHE_ATOM_BTN 39
#define BROCHE_ATOM_LUMIERE 27
#define CANAL_0 0
#define CANAL_1 1

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



  Serial.begin(115200);

}

void loop()
{
  // put your main code here, to run repeatedly:

  // int maLectureKey = digitalRead(BROCHE_ATOM_FIL_BLANC);

  int maLectureBtn = digitalRead(BROCHE_ATOM_BTN);
  int lumiere = myPbHub.analogRead(CANAL_0);
  int angle = myPbHub.analogRead(CANAL_1);


  


  if (maLectureBtn == 0)
  {

    keyPixel2 = CRGB(220, 0, 150); // BLANC

  }
  else
  {

    keyPixel2 = CRGB(0, 0, 0); // BLANC

  }


  // TOUCHE DE CLAVIER
  


monOsc.sendInt( "/lumiere" , lumiere);
monOsc.sendInt( "/angle" , angle);

  



  FastLED.show();

  delay(100);
}

