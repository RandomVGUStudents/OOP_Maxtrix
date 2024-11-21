#include "include/Primary.hpp"
#include "ModeSelection.hpp"

State button[3]; //Mode selection.

void State::back()
{
    button[1].rect = {20, 40, 50, 50};
    DrawRectangleRounded(button[1].rect, roundness, segments, LIGHTGRAY);

    DrawTexture(Back_Arrow, button[1].rect.x, button[1].rect.y, WHITE); // Draw back button texture.
    
    if(CheckCollisionPointRec(GetMousePosition(),button[1].rect)) button[1].mouse_over_box = true;
    else if (!CheckCollisionPointRec(GetMousePosition(),button[1].rect)) {button[1].mouse_over_box = false;}
    if(button[1].mouse_over_box)
    {   
        DrawRectangleRounded(button[1].rect, roundness, segments, TRANSPARENT_BEIGE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = 0;
    }
    
} 

void State::determinant_logic()
{
    button[2].rect = {screenWidth/2 - 100, screenHeight/2 - 200, 200, 50};
    DrawRectangleRounded(button[2].rect, roundness, segments, LIGHTGRAY);
    DrawText("< Determinant >", button[2].rect.x + 25, button[2].rect.y + 15, font_size, BLACK);
    
    if(CheckCollisionPointRec(GetMousePosition(),button[2].rect)) button[2].mouse_over_box = true;
    else if(!CheckCollisionPointRec(GetMousePosition(),button[2].rect)) {button[2].mouse_over_box = false;}

    if(button[2].mouse_over_box == true)
    {   
        DrawRectangleRounded(button[2].rect, roundness, segments, TRANSPARENT_BEIGE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = 1;
    }
    
}

void State::co_factor()
{
    button[3].rect = {screenWidth/2 - 100, screenHeight/2 - 130, 200, 50};
    DrawRectangleRounded(button[3].rect, roundness, segments, LIGHTGRAY);
    DrawText("< Co-Factor >", button[3].rect.x + 35, button[3].rect.y + 15, font_size, BLACK);
    
    if(CheckCollisionPointRec(GetMousePosition(),button[3].rect)) button[3].mouse_over_box = true;
    else if(!CheckCollisionPointRec(GetMousePosition(),button[3].rect)) button[3].mouse_over_box = false;

    if(button[3].mouse_over_box)
    {   
        DrawRectangleRounded(button[3].rect, roundness, segments, TRANSPARENT_BEIGE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = 2;
    }
    
}
