#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) <--- Can be optimised
int maxGold(const vector<vector<int>> &mine)
{
    int n = mine.size();
    int m = mine[0].size();

    vector<vector<int>> dp(n, vector<int>(m));

    for (int col = 0; col < m; col++)
        dp[0][col] = mine[0][col];

    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (col != 0 && col != m - 1)
                dp[row][col] = mine[row][col] + max(dp[row - 1][col - 1], max(dp[row - 1][col], dp[row - 1][col + 1]));
            else if (col == 0)
                dp[row][col] = mine[row][col] + max(dp[row - 1][col], dp[row - 1][col + 1]);
            else if (col == m - 1)
                dp[row][col] = mine[row][col] + max(dp[row - 1][col - 1], dp[row - 1][col]);
        }
    }

    int maxG = INT_MIN;
    for (int col = 0; col < m; col++)
        maxG = max(dp[n - 1][col], maxG);
    return maxG;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m)
int maxGoldOptimised(const vector<vector<int>> &mine)
{
    int n = mine.size();
    int m = mine[0].size();

    vector<int> prevDp(m);
    vector<int> dp(m);

    for (int col = 0; col < m; col++)
        prevDp[col] = mine[0][col];

    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (col != 0 && col != m - 1)
                dp[col] = mine[row][col] + max(prevDp[col - 1], max(prevDp[col], prevDp[col + 1]));
            else if (col == 0)
                dp[col] = mine[row][col] + max(prevDp[col], prevDp[col + 1]);
            else if (col == m - 1)
                dp[col] = mine[row][col] + max(prevDp[col - 1], prevDp[col]);
        }
        prevDp = dp;
        dp = vector<int>(m);
    }

    int maxGold = INT_MIN;
    for (int col = 0; col < m; col++)
        maxGold = max(prevDp[col], maxGold);
    return maxGold;
}

int main()
{
    vector<vector<int>> mine = {
        {3, 2, 12, 15, 10},
        {6, 19, 7, 11, 17},
        {8, 5, 12, 32, 21},
        {3, 20, 2, 9, 7},
    };

    vector<vector<int>> mine2 = {
        {42, 31, 25},
        {6, 46, 35},
        {20, 21, 44},
        {28, 30, 17},
        {10, 43, 26},
    };
    cout << maxGold(mine) << '\n';
    cout << maxGoldOptimised(mine);
}