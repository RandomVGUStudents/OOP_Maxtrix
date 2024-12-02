#include "Inverse.hpp"
#include <iostream>

using namespace std;

void Inverse::input() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    // Resize the matrix to n x n
    matrix.resize(n, vector<double>(n));

    // Input the matrix elements
    cout << "Enter the elements of the matrix (row by row):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "matrix[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void Inverse::calculateInverse()
{
    if (matrix.empty())
    {
        cout << "Matrix is empty. Please input a valid matrix." << endl;
        return;
    }

    int n = matrix.size();
    inverse = matrix; // Start with a copy of the matrix

    // Create an augmented matrix [matrix | identity]
    vector<vector<double>> augmented(n, vector<double>(2 * n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            augmented[i][j] = matrix[i][j]; // Original matrix on the left
        }
        for (int j = n; j < 2 * n; ++j)
        {
            augmented[i][j] = (i == j - n) ? 1.0 : 0.0; // Identity matrix on the right
        }
    }

    // Perform Gaussian elimination
    for (int i = 0; i < n; ++i) {
        double pivot = augmented[i][i];
        if (pivot == 0) {
            cout << "Matrix is singular and cannot be inverted." << endl;
            inverse.clear();
            return;
        }

        // Normalize the pivot row
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmented[i][j + n];
        }
    }
}