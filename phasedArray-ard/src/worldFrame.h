#include <iostream>
#include <FastLED.h>
#include <Arduino.h>
#include <Vertex.h>
#include <vector>

#ifndef DISPLAY_FRAME_H
#define DISPLAY_FRAME_H
    class displayFrame{
        public:
            std::vector<Vertex> points;
    };
#endif