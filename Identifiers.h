#pragma once
#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#define screenWidth 800 // ScreenWidth.
#define screenHeight 600 // ScreenHeight.
#define number_size 25 // Number font size.
#define font_size 20 // Font size.
#define matrix_box 9 // Numbers of matrix boxes.

class State //To define calculator state.
{
    private:
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};
    
    public:
    int state; //default = 0; determinate = 1;
    bool button_state;
    bool mouse_over_box = false;
    void selection();

};

class Uis
{
    private:
    //box
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};
    
    public:
    void uis();
};

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

class Calculations
{
    public:
    void determinant();
    struct determinant_result
    {
        double two_x_two;

        double block1;
        double block2;
        double block3;
        double three_x_three;
    };
};

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
