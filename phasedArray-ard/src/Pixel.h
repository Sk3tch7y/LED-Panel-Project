#include <FastLED.h>
#include <Arduino.h>

#ifndef PIXEL_H
#define PIXEL_H


class Pixel{
  public:
    int x;
    int y;
    int z;
    CRGB color;

    Pixel(int x, int y, CRGB color){
        this->x = x;
        this->y = y;
        this->color = color;
        
    }
    Pixel(int x, int y, int z, CRGB color){
        this->x = x;
        this->y = y;
        this->z = z;
        this->color = color;
    }
    
};

#endif