#include <iostream>
#include <vector>
using namespace std;

// Complexity Analysis
// Max path length = Recursive Tree Height = m + n - 1
// At every recursive call we call the function 2 more times (worst case)
// Time Complexity = O(1) * 2^(m+n-1) = O(1) * 2(m+n) = O(2^(m+n))
// Space Complexity = Max number of fns in call stack at any time = Height of recursive tree = m + n - 1

// Time Complexity = O(2^(m+n))
// Space Complexity = O(m + n)
int paths(const vector<vector<int>> &matrix, int i, int j)
{
    int n = matrix.size();    // Rows in matrix
    int m = matrix[0].size(); // Cols in matrix

    // If we reached a wall, there is no path from there
    if (matrix[i][j] == 1)
        return 0;

    // If we have reached the end, return 1 because there is a path
    if (i == n - 1 && j == m - 1)
        return 1;

    if (i == n - 1) // We are on the bottom row, can't go further down so go to the right
        return paths(matrix, i, j + 1);
    else if (j == m - 1) // We are on the rightmost row, can't go to the right, go down
        return paths(matrix, i + 1, j);
    else
        return paths(matrix, i + 1, j) + paths(matrix, i, j + 1);
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 1, 0, 1},
                                  {0, 0, 0, 0, 1},
                                  {0, 0, 1, 0, 0},
                                  {1, 0, 0, 0, 0}};

    cout << "Printing Matrix\n";
    for (auto row : matrix)
    {
        for (auto elem : row)
        {
            cout << elem << " ";
        }
        cout << '\n';
    }

    cout << "Total Paths = " << paths(matrix, 0, 0); // 7
    return 0;
}