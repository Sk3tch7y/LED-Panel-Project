#include <Arduino.h>
#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 1

CRGB leds[NUM_LEDS];
CRGB ledMatrix[8][8];

void convertToImage(){  
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      ledMatrix[i][j] = leds[i + j];
    }
  }
}


void setCenter(CRGB color){
  leds[27] = color;
  leds[28] = color;
  leds[35] = color;
  leds[36] = color;
}
CRGB interpolate(CRGB colorOne, CRGB colorTwo, float t){
  CRGB finalColor = CRGB(0, 0, 0);
  finalColor = (CRGB(colorOne.r * (1 - t) + colorTwo.r * t, colorOne.g * (1 - t) + colorTwo.g * t, colorOne.b * (1 - t) + colorTwo.b * t));
  return finalColor;
}

void linearGrad(CRGB colorOne, CRGB colorTwo){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      float t = sqrt(i*i + j*j) / (8.0 * sqrt(2));
      CRGB finalColor = interpolate(colorOne, colorTwo, t);
      leds[i*8 + j] = finalColor;
      Serial.println(i*8+j);
      Serial.println(String(finalColor.r) + " " + String(finalColor.g) + " " + String(finalColor.b));
    }
  }
  convertToImage();
}

void centerGrad(CRGB color){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      leds[i + j] = color;
    }
  }
  setCenter(color);
  convertToImage();
}

void rotateAtCenter(float angle = 0.1){
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
  convertToImage();
}
void rotation(){

}

void makeHeart(){
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

void setup() {
  // put your setup code here, to run once:
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello, World!");
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);

  //linearGrad(CRGB(0xFF6800), CRGB(0x990044));
  makeHeart();

}
// center is 26, 27, 36, 37
void loop() {
  FastLED.show();
}

