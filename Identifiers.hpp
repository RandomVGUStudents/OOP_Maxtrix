#pragma once

#ifndef Identifiers.hpp //header guard to prevent re-initiate of the file multiple times.
#define Identifiers.hpp

#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>

#define screenWidth 800 // ScreenWidth.
#define screenHeight 600 // ScreenHeight.
#define number_size 25 // Number font size.
#define font_size 20 // Font size.
#define matrix_rows 3 // Self explainatory.
#define matrix_columns 3 // Self explainatory.

class Numbers 
{
    private:
    //Box
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    //Varible to store inputs
    std::string inputNumber = "";
    double numbersArray;
    bool numberEntered = false;
    float value = 0;

    //Interaction
    bool mouse_over_box = false;    
    int clicked_uppon = 0; // 0 is clear, 1 is hover, 2 is clicked
    void registering_number();
    
    void designating_box(); 
    void draws();
};

extern Numbers box[3][3];

class Result
{
    private:
    Vector2 size;
    Vector2 position;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    void designating_output_box(); // Defining output box and drawing it.
    void draw();
};

//Box standard { x, y }
struct input_box {float x, y;};

/*//float to const char*
const char* floatToString(float value, int precision) {
    //Create a buffer large enough to hold the resulting string
    static char buffer[50];
    //Format the float into the buffer with the specified precision
    snprintf(buffer, sizeof(buffer), "%.*f", precision, value);
    // Return the buffer as const char*
    return buffer;
}*/


#endif