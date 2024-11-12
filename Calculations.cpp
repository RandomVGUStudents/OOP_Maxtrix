#include "Calculations.hpp"
#include "Identifiers.hpp"

Determinant tempor_value[3];

void Determinant::determinant()
{
    for(int a = 0; a < matrix.columns; ++a) // Matrix.columns = 3.
    {
        tempor_value[a].top = 1;
        tempor_value[a].bottom = 1;
    } // Adding a value to tempor_value so that it can be multiply with the matrix.

    if(state_of_mode_determinant.switch_between_mode == false)
    {
        std::cout << "Place Holder" << std::endl;
    }
    else if(state_of_mode_determinant.switch_between_mode == true)
    {
        int clk;
        for(int a = 0; a < matrix.columns; ++a)
        {
            tempor_value[a].pivod = box[a][0].numbersArray;
            clk = 0;
            
            std::cout << "Tempor_value[" << a << "] = " << tempor_value[a].pivod << " = box[" << a << "][0].numbersArray = " << box[a][0].numbersArray << std::endl; // // For troubleshooting

            for(int u = 1; u < matrix.columns; ++u )
            {
                for(int t = 0; t < matrix.columns; ++t)
                {
                    if( t != a && clk == 0)
                    {
                        tempor_value[a].top *= box[t][u].numbersArray;
                        clk = 2;
                        std::cout << "Top box[" << t << "]" << "[" << u << "] = " << box[t][u].numbersArray << std::endl; // For troubleshooting
                    }
                    else if ( t != a )
                    {
                        tempor_value[a].bottom *= box[t][u].numbersArray;
                        clk -= 1;
                        std::cout << "Bottom box[" << t << "]" << "[" << u << "] = " << box[t][u].numbersArray << std::endl; // For troubleshooting
                    }
                }   
            }

            std::cout << "TEMP VALUE TOP [" << a << "]= " << tempor_value[a].top << std::endl; // For troubleshooting.
            std::cout << "TEMP VALUE BOTTOM [" << a << "]= " << tempor_value[a].bottom << std::endl <<std::endl; //For troubleshooting.
        }
        output_box_value.three_three = 0;
        for(int a = 0; a < 3; ++a)
        {
            if( a == 1 ) 
            {                
                output_box_value.three_three -= (tempor_value[a].pivod * (tempor_value[a].top - tempor_value[a].bottom));
            }
            else
            {
                output_box_value.three_three += (tempor_value[a].pivod * (tempor_value[a].top - tempor_value[a].bottom));
            }
        
        std::cout << "Stage [" << a << "] output_box_value.three_three = " << output_box_value.three_three << std::endl;

        }
    }
    std::cout << "OUTPUT_BOX_VALUE = " << output_box_value.three_three << std::endl << std::endl; // For troubleshooting.
}
