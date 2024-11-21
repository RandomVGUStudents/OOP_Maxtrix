#include "include/Primary.hpp"

State Mode;
Uis Main_Menu;

ArrayDeclaration Grid;

MatrixSize Button;

Determinant Solution1;

Result Box;

Cofactor Solution2;

Texture2D Toggle_Button, Back_Arrow, Clear_Button;

int main()
{
    

    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Matrix Calculator");
    Toggle_Button = LoadTexture("assets/Toggle_Button.png");
    Back_Arrow = LoadTexture("assets/Back_Arrow.png");
    Clear_Button = LoadTexture("assets/Clear_Button.png");  

    SetTargetFPS(12);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Main_Menu.uis_initiallizer();
        
        if(Mode.state == 0) // Selection screen.
        {
            Main_Menu.uis_default();
            Mode.determinant_logic();
            Mode.co_factor();
        }
        else if(Mode.state == 1) // Determinant.
        {
            Main_Menu.uis_determinant();
            
            Mode.back();
            Button.mode();
        
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();

            Solution1.determinant_logic();
            Box.designating_output_box_and_draw();
        }
        else if(Mode.state == 2) // Invernse screen.
        {
            Main_Menu.uis_cofactor();
            Mode.back();
            Button.mode();
            
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();

            Solution2.cofactor_logic();
            Solution2.cofactor_draw();

        }
        EndDrawing();
    }
}