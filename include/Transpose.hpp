#pragma once
#ifndef Transpose_hpp
#define Transpose_hpp

#include "Primary.hpp"

class Transpose
{
    private:
    Vector2 position, size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    double number;
    void transpose_logic();
    void transpose_draw();
    

    protected:
};

#endif