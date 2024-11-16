#include "include/Primary.hpp"

State Mode;
Uis Main_Menu;

ArrayDeclaration Grid;

MatrixSize Button;

Determinant Solution;

Result Box;

Texture2D Toggle_Button;

int main()
{
    Grid.designating_box();
    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Matrix Calculator");
    Toggle_Button = LoadTexture("assets/Toggle_Button.png");
    SetTargetFPS(12);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Main_Menu.uis();
        
        switch (Mode.state)
        {
        case 1:
            Grid.draws();
            Grid.registering_number();
            Button.mode();
            Solution.determinant();
            Box.designating_output_box_and_draw();
            break;
        
        default:
            Mode.selection();
            break;
        }
        EndDrawing();
    }
}