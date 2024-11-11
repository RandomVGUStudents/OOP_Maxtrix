#include "Identifiers.hpp"

input_box default_input_box_size = {70, 50};

Numbers box[3][3];
Numbers matrix;


Result output_box;

Determinant_Mode state_of_mode_determinant;
Determinant_Mode state_of_mode_determinant_frame;

void Determinant_Mode::lever_determinant_mode()
{
    state_of_mode_determinant.rect = { screenWidth/2 + 300, screenHeight/2 - 150, 50, 50 }; // Button. 
    
    state_of_mode_determinant_frame.rect = { screenWidth/2 - 310, screenHeight/2 - 250, 200, 130};

    DrawRectangleRounded(state_of_mode_determinant.rect, 0.5, 6, GRAY);

    if(CheckCollisionPointRec(GetMousePosition(), state_of_mode_determinant.rect)) 
    {
        DrawRectangleRounded(state_of_mode_determinant.rect, 0.5, 6, LIGHTGRAY);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !state_of_mode_determinant.switch_between_mode)
        {
            state_of_mode_determinant.switch_between_mode = true; 
        }
        else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && state_of_mode_determinant.switch_between_mode)
        {
            state_of_mode_determinant.switch_between_mode = false;
        }
    }

    if(!state_of_mode_determinant.switch_between_mode)
    {
        DrawRectangleRoundedLines(state_of_mode_determinant_frame.rect, 0.5, 6, 3, RED);
    }
}

void Numbers::designating_box()
{
    matrix.columns = 3; matrix.columns = 3;

    float offset_y = 60, offset_x = 300;
    for(int t = 0; t < matrix.columns; ++t)
    { 
        float offset_y_value = 1;
        for(int u = 0; u < matrix.columns; ++u)
        {
            box[t][u].rect = {screenWidth/2.0f - offset_x, offset_y * offset_y_value, default_input_box_size.x, default_input_box_size.y};
            offset_y_value++;
        }
        offset_x -= 90;
    }   
}

void Numbers::draws()
{
    if(!state_of_mode_determinant.switch_between_mode)
    {
        matrix.columns = 2; matrix.rows = 2;
    }
    else if(state_of_mode_determinant.switch_between_mode == true)
    {matrix.columns = 3; matrix.columns = 3;}

    for(int t = 0; t < matrix.columns; ++t)
    {
    for(int u = 0; u < matrix.columns; ++u)
        {
            DrawRectangleRounded(box[t][u].rect, 0.5, 6, GRAY); 
            
            if(CheckCollisionPointRec(GetMousePosition(),box[t][u].rect)) box[t][u].mouse_over_box = true;
            else box[t][u].mouse_over_box = false;
            if(box[t][u].mouse_over_box)
            {
                DrawRectangleRounded(box[t][u].rect, 0.5, 6, LIGHTGRAY);
                if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
                {
                    box[t][u].clicked_uppon = 2;
                }
            }
            if(!box[t][u].mouse_over_box && box[t][u].inputNumber.size() == 0)
            {
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
                {
                    box[t][u].clicked_uppon = 0;
                }
            }
        }
    }
}

void Numbers::registering_number()
{
    if(!state_of_mode_determinant.switch_between_mode)
    {
        matrix.columns = 2; matrix.rows = 2;
    }
    else if(state_of_mode_determinant.switch_between_mode == true)
    {matrix.columns = 3; matrix.columns = 3;}
    
    for(int t = 0; t < matrix.columns; ++t)
    {
        for(int u = 0; u < matrix.columns; ++u)
        {
            if (box[t][u].clicked_uppon == 2)
            {
                DrawRectangleRounded(box[t][u].rect, 0.5, 6, LIGHTGRAY);
                DrawRectangleRoundedLines(box[t][u].rect, 0.5, 6, 4, BLACK);

                //Get input from keyboard
                int key = GetKeyPressed();
                
                // Handle numeric input (0-9)
                if (key >= 48 && key <= 57)  // ASCII codes for '0' to '9'
                {  
                    box[t][u].inputNumber += (char)key;
                }

                //Handle Enter key to confirm input and store the number
                if (key == KEY_ENTER && !box[t][u].inputNumber.empty()) 
                {
                    int enteredNumber = std::stoi(box[t][u].inputNumber);  // Convert input string to integer
                    box[t][u].numbersArray = enteredNumber;  // Store the number in the array
                    // box_1.inputNumber = "";  // Clear the input for the next number (redundent)
                    box[t][u].numberEntered = true;
                    box[t][u].clicked_uppon = 0;
                }
                        
                //Handle Backspace to delete the last digit
                if (key == KEY_BACKSPACE && !box[t][u].inputNumber.empty()) box[t][u].inputNumber.pop_back();  // Remove the last character
                if (key == KEY_BACKSPACE && box[t][u].inputNumber.empty()) box[t][u].numbersArray = 0;

                //Terminal troubleshooting.
                printf("box[%d][%d] = %.00lf \n", t, u, box[t][u].numbersArray);
            }
                // Display the input number so far
            if (!box[t][u].inputNumber.empty()) DrawText((box[t][u].inputNumber).c_str(), box[t][u].rect.x + 10, box[t][u].rect.y + 13, number_size, BLACK);
        }
    }
}

void Result::designating_output_box()
{
    float offset_x = 100, offset_y = 150;
    output_box.rect = {screenWidth/2.0f, screenHeight/2.0f + offset_y, default_input_box_size.x * 4, default_input_box_size.y };
}

void Result::draw()
{
    DrawRectangleRounded(output_box.rect, 0.5, 6, GRAY);
    //if(two_x_two_state.first) {DrawText(TextFormat("%.00lf",result.two_x_two), output_box.rect.x + 15, output_box.rect.y + 13, number_size, BLACK);}

}
