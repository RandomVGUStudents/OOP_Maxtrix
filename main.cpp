#include "include/Primary.hpp"

Uis Main_Menu;

ArrayDeclaration Grid;

MatrixSize Button;

Determinant Solution1;

Result Box;

Cofactor Solution2;
Transpose Solution2_1;

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
        
        if(btn.state == 1) // Selection screen.
        {
            Main_Menu.uis_default();
            btn.selection();
        }
        else if(btn.state == 2) // Determinant.
        {
            Main_Menu.uis_determinant();
            
            btn.back();
            Button.mode(); // Change matrix size.
        
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();

            Solution1.determinant_logic();
            Box.designating_output_box_and_draw();
        }
        else if(btn.state == 3 || btn.state == 31) // Cofactor screen.
        {
            if(btn.state == 31)
            {
                btn.cofact_switch(); // Switch to cofactor answer print.
                Solution2_1.transpose_draw();
            }
            else
            {
                btn.trans_switch(); // Switch to transpose answer print.
                Solution2.cofactor_draw();
            }

            Main_Menu.uis_cofactor();
            btn.back();
            Button.mode(); // Change matrix size.
            
            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();

            Solution2.cofactor_logic();
            Solution2_1.transpose_logic();
        }

        else if (btn.state == 4) // Adjoint
        {
            Main_Menu.uis_adjoint();
            btn.back();
            Button.mode(); // Change matrix size.

            Grid.designating_box();
            Grid.draws();
            Grid.registering_number();
            Grid.clear();
        }

        else if (btn.state == 5) // Linear system screen
        {
            Main_Menu.uis_LinearSystem();
            btn.back();
            Button.mode(); // Change matrix size.

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
