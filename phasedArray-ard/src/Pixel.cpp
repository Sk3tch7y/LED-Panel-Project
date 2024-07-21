#include "Pixel.h";

Pixel::Pixel(const int& x, const int& y, const int& a, const CRGB& color){
    this->x = x;
    this->y = y;
    this->a = a;
    this->Color = color;
}
Pixel::Pixel(const int& x, const int& y, const int& a){
    this->x = x;
    this->y = y;
    this->a = a;
    this->Color = CRGB::Black;
}
int Pixel::returnLinearLocation(){
    return this->x * 8 + this->y;
}
void Pixel::setCoordinatesFromLinearLocation(const int& linearLocation){
    this->x = linearLocation / 8;
    this->y = linearLocation % 8;
}
CRGB Pixel::returnColor(){
    CRGB adjustedColor = this->Color;
    adjustedColor.nscale8(this->a);
    return adjustedColor;
}

void Pixel::setX(const int& x){
    this->x = x;
}
void Pixel::setY(const int& y){
    this->y = y;
}
void Pixel::setA(const int& a){
    this->a = a;
}
void Pixel::setColor(const CRGB& color){
    this->Color = color;
}
