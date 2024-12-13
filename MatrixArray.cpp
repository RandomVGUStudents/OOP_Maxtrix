#include "include/Primary.hpp"

input_box default_input_box_size = {70, 50};

extern Texture2D Toggle_Button;

MatrixSize is_three_by_three;

void MatrixSize::mode()
{
    bool isLinear = Grid.calculate == "Linear";
    float width = screenWidth / 2;
    if (isLinear) width += 100;
    
    is_three_by_three.rect = { screenWidth/2 + 80, screenHeight/2 - 220, 50, 50 }; // Button. 
    DrawRectangleRounded(is_three_by_three.rect, roundness, segments, LIGHTGRAY);
    DrawTexture(Toggle_Button, is_three_by_three.rect.x, is_three_by_three.rect.y, WHITE); // Draw change matrix size button.
    DrawText( "M Size:" , is_three_by_three.rect.x - 80, is_three_by_three.rect.y + 15, font_size, BLACK);

    int fontSize = 20;
    Vector2 textSize = MeasureTextEx(GetFontDefault(), "2|3", fontSize, 1);
    float textX = is_three_by_three.rect.x + (is_three_by_three.rect.width - textSize.x) / 2;
    float textY = is_three_by_three.rect.y + (is_three_by_three.rect.height - textSize.y) / 2;
    DrawText("2|3", textX, textY, fontSize, BLACK);
    
    if(CheckCollisionPointRec(GetMousePosition(), is_three_by_three.rect)) // Mode lever.
    {
        DrawRectangleRounded(is_three_by_three.rect, roundness, segments, TRANSPARENT_BEIGE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !is_three_by_three.state)
        {
            is_three_by_three.state = true;
            matrix.columns = 3; matrix.rows = 3;
        }
        else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_three_by_three.state)
        {
            is_three_by_three.state = false;
            matrix.columns = 2; matrix.rows = 2;
        }
    }
}

ArrayDeclaration is_clear;
extern Texture2D Clear_Button;

void ArrayDeclaration::clear() // Clear Button function
{
    bool isLinear = calculate == "Linear";
    float width = screenWidth / 2;
    if (isLinear) width += 100;
    is_clear.rect = { screenWidth/2 + 80, screenHeight/2 - 160, 50, 50 }; // Button. 
    DrawRectangleRounded(is_clear.rect, roundness, segments, LIGHTGRAY);
    DrawTexture(Clear_Button, is_clear.rect.x, is_clear.rect.y, WHITE); // Draw Clear Button Texture.
    DrawText( "Clear:" , is_clear.rect.x - 80, is_clear.rect.y + 15, font_size, BLACK);

    int fontSize = 20;
    Vector2 textSize = MeasureTextEx(GetFontDefault(), "CLR", fontSize, 1);
    float textX = is_clear.rect.x + (is_clear.rect.width - textSize.x) / 2;
    float textY = is_clear.rect.y + (is_clear.rect.height - textSize.y) / 2;
    DrawText("CLR", textX, textY, fontSize, BLACK);
    
    if(CheckCollisionPointRec(GetMousePosition(), is_clear.rect)) // Mode lever.
    {
        DrawRectangleRounded(is_clear.rect, roundness, segments, TRANSPARENT_BEIGE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            for(int t = 0; t < matrix.columns; ++t)
            {
                for(int u = 0; u < matrix.rows; ++u)
                {
                    box[t][u].numbersArray = 0;
                    while(!box[t][u].inputNumber.empty())
                    {
                        box[t][u].inputNumber.pop_back();
                    }
                }
            }

        if (calculate == "Linear") 
        {
            for (int u = 0; u < matrix.rows; ++u)
                {
                    linearValue[0][u].numbersArray = 0;
                    while (!linearValue[0][u].inputNumber.empty())
                    {
                        linearValue[0][u].inputNumber.pop_back();
                    }
                }
            }
        }
    }
}

ArrayDeclaration box[3][3], matrix;

void ArrayDeclaration::designating_box()
{
    float offset_y = 80, offset_x = 300;
    for(int t = 0; t < matrix.columns; ++t)
    { 
        float offset_y_value = 1;
        for(int u = 0; u < matrix.columns; ++u)
        {
            box[t][u].rect = {screenWidth/2.0f - offset_x, offset_y * offset_y_value, default_input_box_size.x, default_input_box_size.y}; // Matrix Boxes
            offset_y_value++;
        }
        offset_x -= 90;
    }   
}

void ArrayDeclaration::draws()
{
    for(int t = 0; t < matrix.columns; ++t)
    {
        for(int u = 0; u < matrix.columns; ++u)
        {
            DrawRectangleRounded(box[t][u].rect, roundness, segments, LIGHTGRAY); 
            
            if(CheckCollisionPointRec(GetMousePosition(),box[t][u].rect)) box[t][u].mouse_over_box = true;
            else box[t][u].mouse_over_box = false;
            if(box[t][u].mouse_over_box)
            {
                DrawRectangleRounded(box[t][u].rect, roundness, segments, BEIGE);
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

    if (calculate == "Linear") {
        for (int u = 0; u < matrix.columns; ++u)
        {
            DrawRectangleRounded(linearValue[0][u].rect, roundness, segments, LIGHTGRAY);

            if (CheckCollisionPointRec(GetMousePosition(), linearValue[0][u].rect)) linearValue[0][u].mouse_over_box = true;
            else linearValue[0][u].mouse_over_box = false;
            if (linearValue[0][u].mouse_over_box)
            {
                DrawRectangleRounded(linearValue[0][u].rect, roundness, segments, BEIGE);
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    linearValue[0][u].clicked_uppon = 2;
                }
            }
            if (!linearValue[0][u].mouse_over_box && linearValue[0][u].inputNumber.size() == 0)
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    linearValue[0][u].clicked_uppon = 0;
                }
            }
        }
    }
}



void ArrayDeclaration::registering_number()
{   
    for(int t = 0; t < matrix.columns; ++t)
    {
        for(int u = 0; u < matrix.columns; ++u)
        {
            if (box[t][u].clicked_uppon == 2)
            {
                DrawRectangleRounded(box[t][u].rect, roundness, segments, BEIGE);
                DrawRectangleRoundedLines(box[t][u].rect, roundness, segments, 4, BLACK);

                //Get input from keyboard
                int key = GetKeyPressed();
                
                // Handle numeric input (0-9)
                if (key >= 48 && key <= 57 && box[t][u].inputNumber.size() < MAX_DIGITS)    // ASCII codes for '0' to '9' & avoid box overflow.
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
                //printf("box[%d][%d] = %.00lf \n", t, u, box[t][u].numbersArray);
            }
                // Display the input number so far
            if (!box[t][u].inputNumber.empty()) DrawText((box[t][u].inputNumber).c_str(), box[t][u].rect.x + 10, box[t][u].rect.y + 13, number_size, BLACK);
        }
    }



    /*
        New change 1.1
    */
    if (calculate == "Linear") {
        for (int u = 0; u < matrix.columns; ++u)
        {
            if (linearValue[0][u].clicked_uppon == 2)
            {
                DrawRectangleRounded(linearValue[0][u].rect, roundness, segments, BEIGE);
                DrawRectangleRoundedLines(linearValue[0][u].rect, roundness, segments, 4, BLACK);

                //Get input from keyboard
                int key = GetKeyPressed();

                // Handle numeric input (0-9)
                if (key >= 48 && key <= 57 && linearValue[0][u].inputNumber.size() < MAX_DIGITS)    // ASCII codes for '0' to '9' & avoid box overflow.
                {
                    linearValue[0][u].inputNumber += (char)key;
                }

                //Handle Enter key to confirm input and store the number
                if (key == KEY_ENTER && !linearValue[0][u].inputNumber.empty())
                {
                    int enteredNumber = std::stoi(linearValue[0][u].inputNumber);  // Convert input string to integer
                    linearValue[0][u].numbersArray = enteredNumber;  // Store the number in the array
                    // box_1.inputNumber = "";  // Clear the input for the next number (redundent)
                    linearValue[0][u].numberEntered = true;
                    linearValue[0][u].clicked_uppon = 0;
                }

                //Handle Backspace to delete the last digit
                if (key == KEY_BACKSPACE && !linearValue[0][u].inputNumber.empty()) linearValue[0][u].inputNumber.pop_back();  // Remove the last character
                if (key == KEY_BACKSPACE && linearValue[0][u].inputNumber.empty()) linearValue[0][u].numbersArray = 0;

                //Terminal troubleshooting.
                //printf("box[%d][%d] = %.00lf \n", t, u, box[t][u].numbersArray);
            }
            // Display the input number so far
            if (!linearValue[0][u].inputNumber.empty()) DrawText((linearValue[0][u].inputNumber).c_str(), linearValue[0][u].rect.x + 10, linearValue[0][u].rect.y + 13, number_size, BLACK);
        }
    }
}

