#pragma once

#ifndef Identifiers_hpp //header guard to prevent re-initiate of the file multiple times.
#define Identifiers_hpp

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

//Box standard { x, y }
struct input_box {float x, y;};

extern struct input_box default_input_box_size;

class ArrayDeclaration 
{
    private:
    //Box
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    int rows, columns; // Self explainatory.

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

extern ArrayDeclaration matrix, box[3][3];

class Determinant_Mode
{
    private:
    //Box
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};

    public:
    bool switch_between_mode = false;
    void lever_determinant_mode();
};

extern Determinant_Mode state_of_mode_determinant;



#endif