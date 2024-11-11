#include "Identifiers.hpp"
#include "Calculations.hpp"
#include "UserInterface.hpp"

State Mode;
Uis Main_Menu;

Numbers Grid;

Determinant_Mode Button;

Determinant Solution;

Result Box;

int main()
{
    Grid.designating_box();
    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Test_1");
    SetTargetFPS(12);

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
            Button.lever_determinant_mode();
            Solution.determinant();
            Box.designating_output_box_and_draw();
        }
        EndDrawing();
    }
}