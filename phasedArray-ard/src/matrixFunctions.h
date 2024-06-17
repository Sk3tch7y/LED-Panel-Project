
#include <FastLED.h>
#include <cmath>
#include <Arduino.h>

#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H
void rasterize(CRGB displayMatrix[], CRGB ledMatrix[8][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      displayMatrix[i * 8 + j] = ledMatrix[i][j];
    }
  }
}

void rasterize(CRGB tempMatrix[8][8], CRGB ledMatrix[8][8]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      tempMatrix[i][j] = ledMatrix[i][j];
    }
  }
}


void rotateDisplay(int angle, CRGB ledMatrix[8][8]){
  CRGB temp[8][8];
  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      int x = i*cos(angle) - j*sin(angle);
      int y = i*sin(angle) + j*cos(angle);
      //Serial.println("I = " + String(i) + "->" + String(x) + "\n J = " + String(j) + "->" + String(y));
      temp[i][j] = ledMatrix[x][y];
    }
  }
  rasterize(temp, ledMatrix);  
}
#endif
