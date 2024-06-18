

#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    public:
        int x;
        int y;
        int z;
        int w;
        Vector(int x, int y, int z, int w = 1){
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }
};
#endif