#include <Arduino.h>
#include <FastLED.h>
#include <math.h>
#include <imageFunctions.h>
#include <matrixFunctions.h>

#define NUM_LEDS 64
#define DATA_PIN 1

CRGB leds[NUM_LEDS];
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

void convertToImage(){  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      //Serial.println(ledMatrix[i][j].r);
      ledMatrix[i][j] = leds[i * 8 + j];
    }
  }
}

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello, World!");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  
  FastLED.setBrightness(100);
  //makeHeart();

}
void loop() {
  //rotateDisplay(180, ledMatrix);
  //linearGrad(CRGB(0xFF6800), CRGB(0x990044), ledMatrix);
  convertToImage();
  FastLED.show();
  //Serial.println("Done Loop");
}

