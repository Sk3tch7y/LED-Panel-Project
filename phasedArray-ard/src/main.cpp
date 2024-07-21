#include <Arduino.h>
#include <FastLED.h>
#include <math.h>
#include <list>
#include "Pixel.h"

#define NUM_LEDS 64
#define DATA_PIN 1

CRGB displayBuffer[NUM_LEDS];
std::list<Pixel> frameBuffer;

void getFrame(std::list<Pixel>& pixels){
  for(int i = 0; i < NUM_LEDS; i++){
    Pixel currentPixel = Pixel(0, 0, 0);
    currentPixel.setCoordinatesFromLinearLocation(i);
    currentPixel.setColor(displayBuffer[i]);
    pixels.push_back(currentPixel);
  }
}

void convertToImage(){  
  while(!frameBuffer.empty()){
    Pixel currentPixel = frameBuffer.front();
    frameBuffer.pop_front();
    displayBuffer[currentPixel.returnLinearLocation()] = currentPixel.returnColor();
  }
}

void createFrameBuffer(){

}

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello, World!");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(displayBuffer, NUM_LEDS);
  
  FastLED.setBrightness(5);

}

void loop() {
  //linearGrad(CRGB(0x00FF00), CRGB(0x0000FF), frameBuffer);
  convertToImage();
  queueNewFrame();
  FastLED.show();
  delay(1000);
  delete 
  //Serial.println("Done Loop");
}

