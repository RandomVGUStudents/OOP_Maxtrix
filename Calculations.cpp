#include "Calculations.hpp"
#include "Identifiers.hpp"

void Determinant::determinant()
{
    if(box[0][2].numbersArray == NULL && box[2][0].numbersArray == NULL)
    {
        for(int t = 0; t < matrix.rows - 1; ++t)
        {
            for(int u = 0; u < matrix.columns - 1; ++u)
            {
                std::cout << "box [" << t << "][" << u << "] = " <<box[t][u].numbersArray << std::endl;
            }   
        }
    }
}