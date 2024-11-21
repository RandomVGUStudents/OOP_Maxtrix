#pragma once
#ifndef ModeSelection_hpp
#define ModeSelection_hpp

#include "include/Primary.hpp"

extern Texture2D Back_Arrow;
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
    void co_factor();
    void determinant_logic();
    void back();
};

#endif