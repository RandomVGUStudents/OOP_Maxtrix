#include "Linear system.hpp"
#include <iostream>

using namespace std;

bool LinearSystem::setSystem(const vector<vector<double>>& matrix, const vector<double>& constants)
{
	if (matrix.empty() || matrix.size() != matrix[0].size() || constants.size() != matrix.size())
	{
		// Print out for debugging
		cout << "Matrix must be square and match the size of constants" << endl;
		return false;
	}
	A = matrix;
	B = constants;
	return true;
}

vector<double> LinearSystem::solve()
{
	//Number of equations
	int n = A.size();

	// Augmented Matrix [ A | B ]
	vector<vector<double>> augmented(n, vector<double>(n + 1));

	// Copy the coefficient matrix A to augmented matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			augmented[i][j] = A[i][j];
		}
		// Add the constants vector to the last column
		augmented[i][n] = B[i];
	}

	// Gausian eliminatiion
	for (int i = 0; i < n; i++)
	{
		double pivot = augmented[i][i]; // pivot = the first non-zero entry of each row
		if (pivot == 0)
		{
			// Print out for debugging
			cout << "The matrix is singular -> can't be solve" << endl;
			return {}; // Return an empty vector
		}

		// Normalize the pivot by dividing all elements by the pivot
		for (int j = i; j <= n; j++)
		{
			augmented[i][j] /= pivot;
		}

		// Eliminate the column for all rows below and above
		for (int k = 0; k < n; k++)
		{
			if (k != i)
			{
				double factor =  augmented[k][i];
				for (int j = i; j <= n; j++)
				{
					augmented[k][j] -= factor * augmented[i][j];
				}
			}
		}
	}

	solution.resize(n);
	for (int i = 0; i < n; i++)
	{
		solution[i] = augmented[i][n];
	}
	return solution;

}

const vector<double>& LinearSystem::Solution() const
{
	return solution;
}