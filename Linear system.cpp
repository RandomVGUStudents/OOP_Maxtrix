#include "include/Linear system.hpp"
#include "include/Primary.hpp"
#include <iostream>

using namespace std;

void LinearSystem::inputSystem()
{
    int n;
    cout << "Enter the size of the matrix (2 for 2x2, 3 for 3x3): " << endl;
    cin >> n;

    if (n != 2 && n != 3)
    {
        cout << "Only 2x2 and 3x3 matrices are supported." << endl;
        return;
    }

    // Input coefficient matrix
    A.resize(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: " << endl;
            cin >> A[i][j];
        }
    }

    // Input constant vector
    B.resize(n);
    cout << "Enter the constant vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "B[" << i + 1 << "]: " << endl;
        cin >> B[i];
    }
}

// Solving the linear system
void LinearSystem::LS_logic()
{
    vector <double> tempB;
    vector<vector<double>> tempA;



    int n = matrix.columns;
    bool fillAll = true;
    for (int j = 0; j < n; j++) {
        vector<double> v;
        for (int i = 0; i < n; i++) {
            if (!box[i][j].numberEntered) {
                fillAll = false;
            }
            v.push_back(box[i][j].numbersArray);
        }
        tempA.push_back(v);
    }

    for (int i = 0;i < n; i++) {
        if (!linearValue[0][i].numberEntered) {
            fillAll = false;
        }
        tempB.push_back(linearValue[0][i].numbersArray);
    }
    if (!fillAll || n == 0)
    {
        cout << "Please provide valid inputs." << endl;
        return;
    }

    A.clear();
    B.clear();
    solution.clear();
    A = tempA;
    B = tempB;

    // Ensure the right size of matrix
    if (A.size() != A[0].size() || B.size() != A.size())
    {
        cout << "Matrix must be square and match the size of constants." << endl;
        return;
    }

    // Number of equations

    // Augmented Matrix [ A | B ]
    vector<vector<double>> augmented(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            augmented[i][j] = A[i][j];
        }
        augmented[i][n] = B[i];
    }

    // Gaussian elimination
    for (int i = 0; i < n; i++)
    {
        double pivot = augmented[i][i];
        if (pivot == 0)
        {
            cout << "The matrix is singular -> can't be solved." << endl;
            return;
        }

        for (int j = i; j <= n; j++)
        {
            augmented[i][j] /= pivot;
        }

        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = augmented[k][i];
                for (int j = i; j <= n; j++)
                {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Extract the solution
    solution.resize(n);
    for (int i = 0; i < n; i++) {
        solution[i] = augmented[i][n];
    }

    // Output for debugging
    cout << "Solution:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

// Method to draw the system (matrix, constants, and solution)
void LinearSystem::draw()
{
    if (A.empty() || B.empty()) {
        cout << "The system has not been set. Nothing to draw." << endl;
        return;
    }

    // Starting position of the matrix
    float offset_y = 80, offset_x = 30;
    float cell_width = 100, cell_height = 50;
    float start_x = 100, start_y = 100;

    //// Draw the coefficient matrix A
    //for (int i = 0; i < A.size(); ++i) {
    //    for (int j = 0; j < A[i].size(); ++j) {
    //        Rectangle rect = { start_x + offset_x + j * cell_width, start_y + offset_y + i * cell_height, cell_width, cell_height };
    //        DrawRectangleRounded(rect, 0.2, 4, LIGHTGRAY);
    //        DrawText(TextFormat("%.2lf", A[i][j]), rect.x + 15, rect.y + 15, 20, BLACK);
    //    }

    //    // Draw the constants column B
    //    Rectangle rectB = { start_x + offset_x + A[i].size() * cell_width + 50, start_y + offset_y + i * cell_height, cell_width, cell_height };
    //    DrawRectangleRounded(rectB, 0.2, 4, LIGHTGRAY);
    //    DrawText(TextFormat("%.2lf", B[i]), rectB.x + 15, rectB.y + 15, 20, BLACK);
    //}

    // Draw solution if available
    if (!solution.empty()) {
        float solution_start_x = start_x + offset_x;
        float solution_start_y = start_y + offset_y + (A.size() + 1) * cell_height;

        for (int i = 0; i < solution.size(); ++i) {
            Rectangle rectSolution = { solution_start_x + i * cell_width + 20 * i, solution_start_y + 20, cell_width, cell_height };
            DrawRectangleRounded(rectSolution, 0.2, 4, LIGHTGRAY);
            DrawText(TextFormat("x%d = %.2lf", (int)i + 1, solution[i]), rectSolution.x + 10, rectSolution.y + 15, 20, BLACK);
        }
    }
    else {
        // If no solution, display a message
        float nosolution_x = start_x + offset_x;
        float nosolution_y = start_y + offset_y + (A.size() + 1) * cell_height;
        DrawText("Solution is not available.", nosolution_x, nosolution_y, 20, RED);
    }
}
