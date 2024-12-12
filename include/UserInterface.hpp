#pragma once

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include "MatrixArray.hpp"

class Uis
{
    private:
    //box
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};
    
    public:
    void uis_initiallizer();
    void uis_default();
    void uis_determinant();
    void uis_cofactor();
    void uis_adjoint();
    void uis_LinearSystem();
};

#endif
