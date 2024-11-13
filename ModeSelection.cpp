#include "ModeSelection.hpp"

State button; //Mode selection.

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