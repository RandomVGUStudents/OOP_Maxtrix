#pragma once
#ifndef ModeSelection_hpp
#define ModeSelection_hpp



#include "include/Primary.hpp"

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

#endif