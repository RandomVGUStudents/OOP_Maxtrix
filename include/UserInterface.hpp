#pragma once

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include "Identifiers.hpp"

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

#endif