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
    // Function to transpose the matrix
    void transpose(double matrix[3][3], double transposed[3][3], int row, int col, int size);
};

#endif
