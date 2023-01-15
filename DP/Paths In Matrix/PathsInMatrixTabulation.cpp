#include <iostream>
#include <vector>
using namespace std;

// Can be space optimised further --- See below
// Time Complexity = O(nm)
// Space Complexity = O(nm) --- Can be optimised
int paths(const vector<vector<int>> &matrix)
{
    if (matrix[0][0] == 1) // If the starting cell has a wall then we can't reach the end at all
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[m];

    dp[0][0] = 1;
    bool wallFound = false;
    for (int i = 1; i < n; i++)
    {
        // For the leftmost col, there is only one path that is from the top
        // If we reach a wall then further there will be no paths at all in the leftmost col
        if (matrix[i][0] == 1)
            wallFound = true;
        // Will fill 1 until a wall is seen in the leftmost col, once a wall is found, will fill 0 in remaining leftmost col cells
        dp[i][0] = (int)(!wallFound);
    }

    wallFound = false;
    for (int j = 1; j < m; j++) // For the topmost row, there is only one path that is from the left
    {
        if (matrix[0][j] == 1)
            wallFound = true;
        dp[0][j] = (int)(!wallFound); // Fill 1 in the topmost row cells until a wall is seen. Once seen fill 0 in all subsequent cells
    }

    // For every other cells there are 2 paths to come, one from the top and other from the left
    // Total paths at that cell = Total paths from top cell + total paths from left cell
    // BUT!!!
    // If there is a wall at current cell then total paths at that cell will be 0
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 1) // Wall found, total paths from dp[i][j] to the end = 0
                dp[i][j] = 0;
            else // Wall not found, total paths from dp[i][j] to the end = paths from top cell dp[i-1][j] + paths from left cell dp[i][j-1]
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    int res = dp[n - 1][m - 1];

    // Cleanup
    for (int i = 0; i < n; i++)
        delete[] dp[i];
    delete[] dp;

    return res;
}

// We can see that for each element dp[i][j], we just need the values from dp[i-1][j] and dp[i][j-1]
// That means, at every point, we just need 2 rows, previous row (i-1) and current row (i)
// So no need to store the values for all rows and columns, just maintain 2 arrays for 2 rows, prevDp, and dp
// Time Complexity = O(nm)
// Space Complexity = O(2*m) = O(m)
int pathsSpaceOptimised(const vector<vector<int>> &matrix)
{
    if (matrix[0][0] == 1)
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    int *prevDp = new int[m];
    int *dp = new int[m];

    prevDp[0] = 1;
    bool wallFound = false;
    for (int j = 1; j < m; j++)
    {
        if (matrix[0][j] == 1)
            wallFound = true;
        prevDp[j] = (int)(!wallFound);
    }

    for (int i = 1; i < n; i++)
    {
        dp[0] = (matrix[i][0] == 1) ? 0 : prevDp[0];
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 1)
                dp[j] = 0;
            else // Paths from top = prevDp[j] &&&& Paths from left = dp[j - 1]
                dp[j] = prevDp[j] + dp[j - 1];
        }
        prevDp = dp;
        dp = new int[m];
    }

    int res = prevDp[m - 1]; // At the end of every iteration, dp is stored in prevDp and then is made empty, so answer is in prevDp

    // Cleanup
    delete[] prevDp;
    delete[] dp;

    return res;
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

    cout << "Total Paths = " << paths(matrix) << '\n';       // 7
    cout << "Total Paths = " << pathsSpaceOptimised(matrix); // 7
    return 0;
}