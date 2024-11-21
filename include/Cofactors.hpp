#pragma once

#include "Primary.hpp"

class Cofactor
{
    private:
    Vector2 position, size;
    Rectangle rect = {position.x, position.y, size.x, size.y};
    public:
    double pivot, productTop, productBottom, number;
    void cofactor_logic();
    void cofactor_draw();
};
