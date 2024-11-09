#include "Identifiers.hpp"
#include "Calculations.hpp"

State Mode;
Uis Main_Menu;
Numbers Grid;

Determinant Solution;

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
        if(Mode.state == 0) Mode.selection();
        else if(Mode.state == 1)
        {
            Grid.draws();
            Grid.registering_number();
            Box.designating_output_box();
            Box.draw();

            Solution.determinant();
        }
        EndDrawing();
    }
}