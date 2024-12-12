#pragma once 
#ifndef Inverse_hpp
#define Inverse_hpp

#include "Primary.hpp"

class Inverse
{
    private:
    Vector2 position, size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    double number;
    void inverse_logic();
    void inverse_function(double determinant);
    void inverse_draw();
};
#endif


/*#pragma once

#include <vector>

using namespace std;

class Inverse {
public:
    // Input the matrix from the user
    void input();
    // Calculate the inverse of the matrix
    void calculateInverse();
    // Display the original matrix and its inverse
    void drawInverse();

private:
    vector<vector<double>> matrix;      // Original matrix
    vector<vector<double>> inverse;     // Inverse matrix
};*/
