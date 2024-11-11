#include "Calculations.hpp"
#include "Identifiers.hpp"

Determinant tempor_value[3];

void Determinant::determinant()
{
    for(int a = 0; a < 3; ++a)
    {
        tempor_value[a].top = 1;
        tempor_value[a].bottom = 1;
    } // Adding a value to tempor_value so that it can be multiply with the matrix.

    if(state_of_mode_determinant.switch_between_mode = false)
    {
        printf("place holder");
    }
    else if(state_of_mode_determinant.switch_between_mode = true)
    {
        int clk = 0;
        for(int a = 0; a < matrix.columns; ++a)
        {
            tempor_value[0].pivod = box[a][0].numbersArray;
            for(int u = 1; u < matrix.columns; ++u )
            {
                for(int t = 0; t < matrix.columns; ++t)
                {
                    if( u != a && clk == 1)
                    {
                        box[t][u].numbersArray *= tempor_value[a].top;
                        clk = 0;
                        std::cout << "TEMP VALUE = " << tempor_value[a].top << std::endl;
                        std::cout << "Top box[][] = " << box[t][u].numbersArray << std::endl;
                    }
                    else 
                    {
                        box[t][u].numbersArray *= tempor_value[a].bottom;
                        clk = 1;
                        std::cout << "TEMP VALUE = " << tempor_value[a].bottom << std::endl;
                        std::cout << "Bottom box[][] = " << box[t][u].numbersArray << std::endl;
                    }
                }   
            }
        }
        for(int a = 0; a < 3; ++a)
        {
            if( a != 2 ) {output_box_value.three_three += (tempor_value[a].pivod * (tempor_value[a].top - tempor_value[a].bottom));}
            else {output_box_value.three_three -= (tempor_value[a].pivod * (tempor_value[a].top - tempor_value[a].bottom));}
        }
    }
    std::cout << "OUTPUT_BOX_VALUE = " << output_box_value.three_three << std::endl;
}
