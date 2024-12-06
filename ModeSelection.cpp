#include "include/Primary.hpp"
#include "include/ModeSelection.hpp"

State button[4]; //Mode selection.
State btn;

void State::back()
{
    btn.draw(20, 40, 50, 50, 1, "Back");
} 

void State::draw( float a, float b, float x, float y,const int n, string name)
    {

        button[n].rect = {a, b, x, y};
        DrawRectangleRounded(button[n].rect, roundness, segments, LIGHTGRAY);
        //DrawText( "Determinant" , button[2].rect.x + 25, button[2].rect.y + 15, font_size, BLACK);
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
                cout << "state = " << state << endl;
            }
        }
    }

void State::selection()
{
    btn.draw(screenWidth/2 - 100, screenHeight/2 - 200, 200, 50, 2, "Determinant" );
    btn.draw(screenWidth/2 - 100, screenHeight/2 - 130, 200, 50, 3, "Co_factor" );
    btn.draw( screenWidth / 2 - 100, screenHeight / 2 - 60, 200, 50, 4, "Linear_system" );
}























































/*void State::determinant_logic()
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
void State::linear_system()
{
    button[4].rect = { screenWidth / 2 - 100, screenHeight / 2 - 60, 200, 50 };
    DrawRectangleRounded(button[4].rect, roundness, segments, LIGHTGRAY);
    DrawText("< Linear_system >", button[4].rect.x + 35, button[4].rect.y + 15, font_size, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), button[4].rect)) button[4].mouse_over_box = true;
    else if (!CheckCollisionPointRec(GetMousePosition(), button[4].rect)) button[4].mouse_over_box = false;

    if (button[4].mouse_over_box)
    {
        DrawRectangleRounded(button[4].rect, roundness, segments, TRANSPARENT_BEIGE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = 3;
    }

}*/

