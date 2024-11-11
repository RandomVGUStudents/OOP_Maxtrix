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
    else // 3x3 determinant calculation
    {
        // Define matrix elements for easy reference
        int a = box[0].numbersArray;
        int b = box[1].numbersArray;
        int c = box[2].numbersArray;
        int d = box[3].numbersArray;
        int e = box[4].numbersArray;
        int f = box[5].numbersArray;
        int g = box[6].numbersArray;
        int h = box[7].numbersArray;
        int i = box[8].numbersArray;

        // Apply the formula for a 3x3 determinant
        result.three_x_three = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);

        // Print the result for debugging
        std::cout << "3x3 Determinant: " << result.three_x_three << std::endl;
        two_x_two_state.first = false;
}
}
void Calculations::transpose(double matrix[3][3], double transposed[3][3], int row, int col, int size)
{
    // Base case: if I have transposed all rows, stop recursion
    if (row == size) return;

    // If I'm done with a column in the current row, move to the next row
    if (col == size) 
    {
        transpose(matrix, transposed, row + 1, 0, size);
        return;
    }

    // Transpose the element at (row, col) to (col, row)
    transposed[col][row] = matrix[row][col];

    // Recurse to the next column in the current row
    transpose(matrix, transposed, row, col + 1, size);
}
