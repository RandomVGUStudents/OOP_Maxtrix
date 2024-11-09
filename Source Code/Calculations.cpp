#include "Calculations.hpp"
#include "Identifiers.hpp"

void Determinant::determinant()
{
    for(int t = 0; t < matrix_rows; ++t)
    {
        for(int u = 0; u < matrix_columns; ++u)
        {
            std::cout << "box [" << t << "][" << u << "] = " <<box[t][u].numbersArray << std::endl;
        }   
    }
}