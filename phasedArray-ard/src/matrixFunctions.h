
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

void rotateAtCenter(float angle, CRGB ledMatrix[8][8]){
  CRGB tempLeds[8][8];

  // Translate so center of image is at origin, apply rotation, then translate back
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      int x = i - 4; // translate so center is at origin
      int y = j - 4;

      // Apply rotation
      int newX = round(x * cos(angle) - y * sin(angle));
      int newY = round(x * sin(angle) + y * cos(angle));

      // Translate back
      newX += 4;
      newY += 4;

      // If the new position is within the bounds of the image, copy the pixel color
      if(newX >= 0 && newX < 8 && newY >= 0 && newY < 8){
        tempLeds[newX][newY] = ledMatrix[i][j];
      }
    }
  }

  // Copy the rotated image back into the original array
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      ledMatrix[i][j] = CRGB(tempLeds[i][j].r, tempLeds[i][j].g, tempLeds[i][j].b);
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
