#include "Identifiers.h"

State button; //Mode selection.
int state;


Uis user_interafce;
Uis matrix_calculator;

input_box default_input_box_size = {70, 50};

Numbers box[9];

Calculations two_x_two_state;
Calculations::determinant_result result;

Result output_box;

void State::selection()
{
    button.rect = {screenWidth/2 - 100, screenHeight/2 - 75, 200, 150};
    DrawRectangleRoundedLines(button.rect, 0.5, 6, 4, BLACK);
    
    if(CheckCollisionPointRec(GetMousePosition(),button.rect)) button.mouse_over_box = true;
    if(button.mouse_over_box)
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = 1;
    }
}

void Uis::uis()
{
    user_interafce.rect = {10, 28, 780, 550};
    DrawRectangleRoundedLines(user_interafce.rect, 0.1, 6, 4, BLACK);

    matrix_calculator.rect = {screenWidth/2.0f - 150, 10, 300, 30};
    DrawRectangleRounded(matrix_calculator.rect, 0.5f, 6, LIGHTGRAY);
    DrawRectangleRoundedLines(matrix_calculator.rect, 0.5, 6, 4, BLACK);
    DrawText("MATRIX CALCULATOR",matrix_calculator.rect.x + 35, matrix_calculator.rect.y + 5, font_size, BLACK);
}

void Numbers::designating_box()
{
    float offset_y = 60, offset_x = 400, offset_y_value = 1;
    for(int t = 0; t < matrix_box; ++t)
    { 
        if (t % 3 == 0)
        {
            offset_x -= 80; 
            offset_y_value = 1;
        }
        box[t].rect = {screenWidth/2.0f - offset_x, offset_y * offset_y_value, default_input_box_size.x, default_input_box_size.y};
        offset_y_value++;
    }
}

void Numbers::draws()
{
    for(int t = 0; t < matrix_box; ++t)
        {
            DrawRectangleRounded(box[t].rect, 0.5, 6, GRAY); 
            
            if(CheckCollisionPointRec(GetMousePosition(),box[t].rect)) box[t].mouse_over_box = true;
            else box[t].mouse_over_box = false;
            if(box[t].mouse_over_box)
            {
                    DrawRectangleRounded(box[t].rect, 0.5, 6, LIGHTGRAY);
                    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
                    {
                        box[t].clicked_uppon = 2;
                    }
            }
            if(!box[t].mouse_over_box && box[t].inputNumber.size() == 0)
            {
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
                {
                        box[t].clicked_uppon = 0;
                }
            }
        }
}

void Numbers::registering_number()
{
    for(int t = 0; t < matrix_box; ++t)
    {
        
        if (box[t].clicked_uppon == 2)
        {
            DrawRectangleRounded(box[t].rect, 0.5, 6, LIGHTGRAY);
            DrawRectangleRoundedLines(box[t].rect, 0.5, 6, 4, BLACK);

            //Get input from keyboard
            int key = GetKeyPressed();
            
            // Handle numeric input (0-9)
            if (key >= 48 && key <= 57)  // ASCII codes for '0' to '9'
            {  
                box[t].inputNumber += (char)key;
            }

            //Handle Enter key to confirm input and store the number
            if (key == KEY_ENTER && !box[t].inputNumber.empty()) 
            {
                int enteredNumber = std::stoi(box[t].inputNumber);  // Convert input string to integer
                box[t].numbersArray = enteredNumber;  // Store the number in the array
                // box_1.inputNumber = "";  // Clear the input for the next number (redundent)
                box[t].numberEntered = true;
                box[t].clicked_uppon = 0;
            }
                    
            //Handle Backspace to delete the last digit
            if (key == KEY_BACKSPACE && !box[t].inputNumber.empty()) box[t].inputNumber.pop_back();  // Remove the last character
            if (key == KEY_BACKSPACE && box[t].inputNumber.empty()) box[t].numbersArray = 0;

            //Terminal troubleshooting.
            printf("%.00lf \n", box[t].numbersArray);
        }
            // Display the input number so far
        if (!box[t].inputNumber.empty()) DrawText((box[t].inputNumber).c_str(), box[t].rect.x + 10, box[t].rect.y + 13, number_size, BLACK);
    }
}

void Calculations::determinant()
{
    if(box[2].numbersArray == 0)
    {
        double up = 1, down = 1;
        for(int t = 0; t <= 4; t++)
        {
            if(t % 2 == 0 && t != 2) {down *= box[t].numbersArray;}
            else if (t != 2) {up *= box[t].numbersArray;} 
        }
        result.two_x_two = down - up;
        std::cout << "2 x 2 = " <<result.two_x_two << std::endl; // For debugging.
        two_x_two_state.first = true;
    }

    else
    {    
        float top = 1, bottom = 1;
        for(int a = 4; a <= 8; a++)
        {
            if( a % 2 == 0 && a != 6 ) {top *= box[a].numbersArray;}
            else {bottom *= box[a].numbersArray;}
        }
        result.three_x_three = (box[0].numbersArray)*(top - bottom);
        
        /*std::cout << " top = " << top << std::endl; // For debugging.
        std::cout << "bottom = " << bottom << std::endl; // For debugging.
        std::cout << "box[0] = " << box[0].numbersArray << std::endl; // For debugging.
        std::cout << "box[4] = " << box[4].numbersArray << std::endl; // For debugging.
        std::cout << "box[5] = " << box[5].numbersArray << std::endl; // For debugging.
        std::cout << "box[7] = " << box[7].numbersArray << std::endl; // For debugging.
        std::cout << "box[8] = " << box[8].numbersArray << std::endl; // For debugging.
        std::cout << "3 x 3 = " <<result.three_x_three << std::endl; //for debugging.*/

        two_x_two_state.first = false;
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
    if(two_x_two_state.first) {DrawText(TextFormat("%.00lf",result.two_x_two), output_box.rect.x + 15, output_box.rect.y + 13, number_size, BLACK);}
    DrawText(TextFormat("%.00lf",result.three_x_three), output_box.rect.x + 15, output_box.rect.y + 13, number_size, BLACK);
}

