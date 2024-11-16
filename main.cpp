#include "include/Primary.hpp"

State Mode;
Uis Main_Menu;

ArrayDeclaration Grid;

MatrixSize Button;

Determinant Solution;

Result Box;

Texture2D Toggle_Button, Back_Arrow, Clear_Button;

int main()
{
    

    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Matrix Calculator");
    Toggle_Button = LoadTexture("assets/Toggle_Button.png");
    Back_Arrow = LoadTexture("assets/Back_Arrow.png");
    Clear_Button = LoadTexture("assets/Clear_Button.png");  

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Main_Menu.uis();
        
        if(Mode.state == 0) // Selection screen.
        {
            Mode.determinant();
            Mode.inverse();
        }
        else if(Mode.state == 1) // Determinant.
        {
            Button.mode();
            Mode.back();
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();
            Solution.determinant();
            Box.designating_output_box_and_draw();
        }
        else if(Mode.state == 2) // Invernse screen.
        {
            Mode.back();
            Button.mode();
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
        }
        EndDrawing();
    }
}