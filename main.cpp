#include "Identifiers.h"

State Mode;
Uis Main_Menu;
Numbers Grid;
Result Box;


int main()
{
    Grid.designating_box();
    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Test_1");
    SetTargetFPS(25);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Main_Menu.uis();
        if(Mode.state == 0)
        {
        Mode.selection();
        }
        
        if(Mode.state == 1)
        {
            Grid.draws();
            Grid.registering_number();
            Box.designating_output_box();
            Box.draw();
        }
        EndDrawing();
    }
}