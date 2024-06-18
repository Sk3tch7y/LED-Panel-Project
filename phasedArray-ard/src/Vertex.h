#include <FastLED.h>
#include <Arduino.h>

#ifndef VERTEX_H
#define VERTEX_H


class Vertex{
  public:
    int x;
    int y;
    int z;
    CRGB color;

    Vertex(int x, int y, CRGB color){
        this->x = x;
        this->y = y;
        this->z = 0;
        this->color = color;
        
    }
    Vertex(int x, int y, int z, CRGB color){
        this->x = x;
        this->y = y;
        this->z = z;
        this->color = color;
    }
    
};

#endif