#pragma once

#ifndef Calculations_hpp //header guard to prevent re-initiate of the file multiple times.
#define Calculations_hpp

// Custom headers
#include "Identifiers.hpp"
class Determinant
{
    private:
    public:
    
    void determinant();
    double top, bottom, pivod;
};

class Result
{
    private:
    Vector2 size;
    Vector2 position;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    void designating_output_box_and_draw(); // Defining output box and drawing it.
    struct determinant_result
    {
        double two_two, three_three;
    };
};

extern Result::determinant_result output_box_value;

#endif
