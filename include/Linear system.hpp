#pragma once

#include <vector>
#include "Primary.hpp"

using namespace std;

class LinearSystem {
public:
    // Process the entire system (set matrix, solve, and store solution)
    void LS_logic(const vector<vector<double>>& matrix = {}, const vector<double>& constants = {});

    // Draw the system (matrix, constants, and solution)
    void draw();

private:
    vector<vector<double>> A; // Coefficient matrix (2D vector)
    vector<double> B;         // Constants vector
    vector<double> solution;  // Solution vector
};
