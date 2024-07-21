#ifndef PIXEL_H
#define PIXEL_H

#include <Arduino.h>
#include <FastLED.h>

class Pixel{
    public:
        Pixel(const int& x, const int& y, const int& a, const CRGB& color);
        Pixel(const int& x, const int& y, const int& a);
        int returnLinearLocation();
        void setCoordinatesFromLinearLocation(const int& linearLocations);
        CRGB returnColor();
        void setX(const int& x);
        void setY(const int& y);
        void setA(const int& a);
        void setColor(const CRGB& color);
    private:
        int x;
        int y;
        int a;
        CRGB Color;

};

#endif