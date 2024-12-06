#include "include/Primary.hpp"

Uis Main_Menu;

ArrayDeclaration Grid;

MatrixSize Button;

Determinant Solution1;

Result Box;

Cofactor Solution2;

LinearSystem Solution3;

Texture2D Toggle_Button, Back_Arrow, Clear_Button;

int main()
{
    

    // Initiate Window.
    InitWindow(screenWidth, screenHeight, "Matrix Calculator");
    Toggle_Button = LoadTexture("assets/Toggle_Button.png");
    Back_Arrow = LoadTexture("assets/Back_Arrow.png");
    Clear_Button = LoadTexture("assets/Clear_Button.png");  

    SetTargetFPS(30);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Main_Menu.uis_initiallizer();
        
        if(btn.state == 0) // Selection screen.
        {
            Main_Menu.uis_default();
            btn.selection();
            /*Mode.determinant_logic();
            Mode.co_factor();
            Mode.linear_system();*/
        }
        else if(btn.state == 1) // Determinant.
        {
            Main_Menu.uis_determinant();
            
            btn.back();
            Button.mode();
        
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();

            Solution1.determinant_logic();
            Box.designating_output_box_and_draw();
        }
        else if(btn.state == 2) // Invernse screen.
        {
            Main_Menu.uis_cofactor();
            btn.back();
            Button.mode();
            
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();

            Solution2.cofactor_logic();
            Solution2.cofactor_draw();

        }
        else if (btn.state == 3) // Linear system screen
        {
            Main_Menu.uis_LinearSystem();
            btn.back();
            Button.mode();

            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();

            Solution3.LS_logic();
            Solution3.draw();
        }
        EndDrawing();
    }
}
