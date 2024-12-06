#pragma once
#ifndef ModeSelection_hpp
#define ModeSelection_hpp

#include "Primary.hpp"

extern Texture2D Back_Arrow;

class State //To define calculator state.
{
    private:
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};
    string name;
    
    public:
    int state = 0; //default = 0; determinate = 1;
    bool button_state;
    bool mouse_over_box = false;

    void back();
    void selection();
    void draw( float a , float b, float x, float y,const int n, string name);

    /*void co_factor();
    void determinant_logic();
    void linear_system();*/
};

extern State btn;

#endif
