#include "include/Primary.hpp"
#include "include/ModeSelection.hpp"

State button[4]; //Mode selection.
State btn;


void State::draw( float a , float b, float x, float y,const int n, const int name_enable, const char* name)
    {

        button[n].rect = {a, b, x, y};
        DrawRectangleRounded(button[n].rect, roundness, segments, LIGHTGRAY);
        if( name_enable == 1)
        {
        DrawText( name , button[n].rect.x + 25, button[n].rect.y + 15, font_size, BLACK);
        }
        if(CheckCollisionPointRec(GetMousePosition(),button[n].rect)) button[n].mouse_over_box = true;
        else if(!CheckCollisionPointRec(GetMousePosition(),button[n].rect)) {button[n].mouse_over_box = false;}

        if( n == 1 )
        {DrawTexture(Back_Arrow, button[1].rect.x, button[1].rect.y, WHITE);} // Draw back button texture.

        if(button[n].mouse_over_box == true)
        {   
            DrawRectangleRounded(button[n].rect, roundness, segments, TRANSPARENT_BEIGE);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
            {
                btn.state = n - 1;
            }
        }
    }

void State::back()
{
    btn.draw(20, 40, 50, 50, 1, 0, "back");
} 

void State::selection()
{
    btn.draw(screenWidth/2 - 100, screenHeight/2 - 200, 200, 50, 2, 1, "Determinant");
    btn.draw(screenWidth/2 - 100, screenHeight/2 - 130, 200, 50, 3, 1, "Co_factor");
    btn.draw( screenWidth / 2 - 100, screenHeight / 2 - 60, 200, 50, 4, 1, "Linear_system");
}


