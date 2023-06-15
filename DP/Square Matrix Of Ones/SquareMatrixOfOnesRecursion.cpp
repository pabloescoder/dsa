#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(3^(m+n))
// Space Complexity: O(m + n)
int square(const vector<vector<int>> &matrix, int i, int j)
{
    if (i < 0 || j < 0 || matrix[i][j] == 0)
        return 0;
    else
        return 1 + min(square(matrix, i - 1, j - 1), min(square(matrix, i - 1, j), square(matrix, i, j - 1)));
}

int squareCaller(const vector<vector<int>> &matrix)
{
    int maxS = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            maxS = max(square(matrix, i, j), maxS);
    return maxS * maxS; // Return the area of the maxSquare
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