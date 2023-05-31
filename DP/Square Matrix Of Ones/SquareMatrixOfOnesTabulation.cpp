#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) <--- Can be optimised, see below
int square(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int largest = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (matrix[i - 1][j - 1] == 1)
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                largest = max(largest, dp[i][j]);
            }
            else
                dp[i][j] = 0;

    return largest * largest;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m)
int squareOptimised(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prevDp(m + 1);
    vector<int> dp(m + 1);
    int largest = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
            if (matrix[i - 1][j - 1] == 1)
            {
                dp[j] = 1 + min(dp[j - 1], min(prevDp[j - 1], prevDp[j]));
                largest = max(largest, dp[j]);
            }
            else
                dp[j] = 0;
        prevDp = dp;
        dp = vector<int>(m + 1);
    }
    return largest * largest;
}

int main()
{
    vector<vector<int>> matrix =
        {{0, 0, 1, 1, 1, 0},
         {1, 0, 1, 1, 1, 1},
         {0, 1, 1, 1, 1, 0},
         {1, 1, 1, 1, 0, 1},
         {0, 1, 0, 1, 1, 1}};

    cout << square(matrix) << endl;
    cout << squareOptimised(matrix);
}