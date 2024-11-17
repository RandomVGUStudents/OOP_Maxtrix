
#ifndef Prinary_hpp
#define Primary_hpp

#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>

#include "MatrixArray.hpp"
#include "ModeSelection.hpp"
#include "UserInterface.hpp"
#include "Determinants.hpp"
#include "Cofactors.hpp"

#define screenWidth 800 // ScreenWidth.
#define screenHeight 600 // ScreenHeight.
#define number_size 25 // Number font size.
#define font_size 20 // Font size.

#define MAX_DIGITS 4 // Max number that can be entered into a matrix box.

#define roundness 0.5 // roundness of a rect.
#define segments 6 // Segemnts of a curve.

extern Color TRANSPARENT_BEIGE;

#endif