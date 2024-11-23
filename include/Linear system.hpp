#pragma once

#include <vector>


using namespace std;

class LinearSystem {
public:
    // Solves the linear system Ax = b
    vector<double> solve();

    // Set the matrix A and vector b
   
    bool setSystem(const vector<vector<double>>& matrix, const vector<double>& constants);

    // Get the solution vector
    const vector<double>& Solution() const;

    vector<vector<double>> A; // Coefficient matrix (2D vector)
    vector<double> B;              // Constants vector
    vector<double> solution;       // Solution vector
};

