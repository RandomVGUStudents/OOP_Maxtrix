#include "UserInterface.hpp"

Uis user_interafce;
Uis matrix_calculator;

State button; //Mode selection.
int state;

void Uis::uis()
{
    user_interafce.rect = {10, 28, 780, 550};
    DrawRectangleRoundedLines(user_interafce.rect, 0.1, 6, 4, BLACK);

    matrix_calculator.rect = {screenWidth/2.0f - 150, 10, 300, 30};
    DrawRectangleRounded(matrix_calculator.rect, 0.5f, 6, LIGHTGRAY);
    DrawRectangleRoundedLines(matrix_calculator.rect, 0.5, 6, 4, BLACK);
    DrawText("MATRIX CALCULATOR",matrix_calculator.rect.x + 35, matrix_calculator.rect.y + 5, font_size, BLACK);
}

void State::selection()
{
    button.rect = {screenWidth/2 - 100, screenHeight/2 - 75, 200, 80};
    DrawRectangleRounded(button.rect, 0.5, 6, GRAY);
    
    if(CheckCollisionPointRec(GetMousePosition(),button.rect)) button.mouse_over_box = true;
    if(button.mouse_over_box)
    {   
        DrawRectangleRounded(button.rect, 0.5, 6, LIGHTGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = 1;
    }
    else button.mouse_over_box = false;
}