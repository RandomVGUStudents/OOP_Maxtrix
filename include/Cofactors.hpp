#pragma once

#include "Primary.hpp"

class Cofactor
{
    private:
    Vector2 position, size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    double pivot, productTop, productBottom, number;
    void cofactor_logic(); // Co factor logic.
    void cofactor_draw(); // To print out co factor matrix on to the window.
};

extern Cofactor cofactor_value[3][3];
