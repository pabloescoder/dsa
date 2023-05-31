#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
int square(const vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &lookup)
{
    if (i < 0 || j < 0 || matrix[i][j] == 0)
        return 0;
    else if (lookup[i][j] != -1)
        return lookup[i][j];
    else
        return 1 + min(square(matrix, i - 1, j - 1, lookup), min(square(matrix, i - 1, j, lookup), square(matrix, i, j - 1, lookup)));
}

int squareCaller(const vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int maxSquare = 0;
    vector<vector<int>> lookup(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            maxSquare = max(maxSquare, square(matrix, i, j, lookup));
    return maxSquare * maxSquare;
}

int main()
{
    vector<vector<int>> matrix =
        {{0, 0, 1, 1, 1, 0},
         {1, 0, 1, 1, 1, 1},
         {0, 1, 1, 1, 1, 0},
         {1, 1, 1, 1, 0, 1},
         {0, 1, 0, 1, 1, 1}};

    cout << squareCaller(matrix);
}