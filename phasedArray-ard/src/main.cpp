#include <Arduino.h>
#include <FastLED.h>
#include <math.h>
#include <imageFunctions.h>
#include <matrixFunctions.h>
#include <Pixel.h>

#define NUM_LEDS 64
#define DATA_PIN 1

CRGB leds[NUM_LEDS];
/*
CRGB ledMatrix[8][8] = {
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red},
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red},
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red},
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red},
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red},
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red},
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red},
  {CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red,CRGB::Red}
};
*/
Pixel ledMatrix[8][8];


void convertToImage(){  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      //Serial.println(ledMatrix[i][j].r);
      ledMatrix[i][j].color = leds[i * 8 + j];
    }
  }
}

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello, World!");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  FastLED.setBrightness(5);
  //makeHeart();

}

void loop() {
  linearGrad(CRGB(0x00FF00), CRGB(0x000FF), ledMatrix);
  //rotateAtCenter(90, ledMatrix);
  rasterize(leds, ledMatrix);
  FastLED.show();
  delay(1000);
  //Serial.println("Done Loop");
}

