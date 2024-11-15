#include "include/Primary.hpp"

Uis user_interafce;
Uis matrix_calculator;

void Uis::uis()
{
    user_interafce.rect = {10, 28, 780, 550};
    DrawRectangleRoundedLines(user_interafce.rect, 0.1, 6, 4, BLACK);

    matrix_calculator.rect = {screenWidth/2.0f - 150, 10, 300, 30};
    DrawRectangleRounded(matrix_calculator.rect, 0.5f, 6, LIGHTGRAY);
    DrawRectangleRoundedLines(matrix_calculator.rect, 0.5, 6, 4, BLACK);
    DrawText("MATRIX CALCULATOR",matrix_calculator.rect.x + 35, matrix_calculator.rect.y + 5, font_size, BLACK);
}

