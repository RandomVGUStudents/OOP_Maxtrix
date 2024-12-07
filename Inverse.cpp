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

void Inverse::drawInverse() {
    if (matrix.empty() || inverse.empty()) {
        cout << "The matrix has not been set or the inverse is not calculated. Nothing to draw." << endl;
        return;
    }

    // Constants for layout
    float offset_y = 80, offset_x = 30;
    float cell_width = 100, cell_height = 50;
    float start_x = 100, start_y = 100;
    float spacing = 50; // Space between the original matrix and the inverse

    int n = matrix.size();

    // Draw the original matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Rectangle rect = { start_x + offset_x + j * cell_width, start_y + offset_y + i * cell_height, cell_width, cell_height };
            DrawRectangleRounded(rect, 0.2, 4, LIGHTGRAY);
            DrawText(TextFormat("%.2lf", matrix[i][j]), rect.x + 15, rect.y + 15, 20, BLACK);
        }
    }

    // Draw a label for the original matrix
    DrawText("Original Matrix", start_x + offset_x, start_y + offset_y - 40, 20, BLACK);

    // Draw the inverse matrix
    float inverse_start_x = start_x + offset_x + n * cell_width + spacing;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Rectangle rect = { inverse_start_x + j * cell_width, start_y + offset_y + i * cell_height, cell_width, cell_height };
            DrawRectangleRounded(rect, 0.2, 4, LIGHTGRAY);
            DrawText(TextFormat("%.2lf", inverse[i][j]), rect.x + 15, rect.y + 15, 20, BLACK);
        }
    }
