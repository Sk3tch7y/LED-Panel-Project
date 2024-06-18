#include <FastLED.h>
#include <Arduino.h>

#ifndef FRAGMENT_FUNCTIONS_H
#define FRAGMENT_FUNCTIONS_H
void setCenter(CRGB color, CRGB leds[8][8]){
  leds[3][3] = color;
  leds[3][4] = color;
  leds[4][3] = color;
  leds[4][4] = color;
}

//Centered at 0,0 when when x -3 and y -3. Each panel should be treated as a localization of its image
CRGB interpolate(CRGB colorOne, CRGB colorTwo, float t){
  CRGB finalColor = CRGB(0, 0, 0);
  finalColor = (CRGB(colorOne.r * (1 - t) + colorTwo.r * t, colorOne.g * (1 - t) + colorTwo.g * t, colorOne.b * (1 - t) + colorTwo.b * t));
  return finalColor;
}

void linearGrad(CRGB colorOne, CRGB colorTwo, CRGB leds[8][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      float t = sqrt(i*i + j*j) / (8.0 * sqrt(2));
      CRGB finalColor = interpolate(colorOne, colorTwo, t);
      leds[i][j] = finalColor;
    }
  }
}

void centerGrad(CRGB color, CRGB leds[8][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      leds[i][j] = color;
    }
  }
  setCenter(color, leds);
}
//Hardcoded and wont scale with new panels  . 
void makeHeart(CRGB* leds){
  CRGB color = CRGB(CRGB::Purple).nscale8(50);
  leds[2] = color;
  leds[3] = color;
  leds[1*8+1] = color;
  leds[1*8+4] = color;
  leds[2*8+1] = color;
  leds[2*8+5] = color;
  leds[3*8+2] = color;
  leds[3*8+6] = color;
  leds[4*8+2] = color;
  leds[4*8+6] = color;
  leds[5*8+1] = color;
  leds[5*8+5] = color;
  leds[6*8+1] = color;
  leds[6*8+4] = color;
  leds[7*8+2] = color;
  leds[7*8+3] = color;

}

#endif