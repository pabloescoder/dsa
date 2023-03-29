#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// For this problem, memoization sol is better than tabulation, because we do not have to solve all subproblems
// Whereas while filling the DP table, we do have to.

// Time Complexity: O(n * k)
// Space Complexity: O(n * k)   <--- Can be optimised, see below
int knapsack(vector<int> values, vector<int> weights, int k)
{
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 0;
    for (int row = 1; row < n + 1; row++)
        dp[row][0] = 0;
    for (int col = 1; col < k + 1; col++)
        dp[0][col] = 0;

    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < k + 1; col++)
        {
            if (col - weights[row - 1] >= 0)
                dp[row][col] = max(dp[row - 1][col],
                                   values[row - 1] + dp[row - 1][col - weights[row - 1]]);
            else
                dp[row][col] = dp[row - 1][col];
        }
    }
    return dp[n][k];
}

// Memoization is still better wrt Time Complexity for this problem
// Time Complexity: O(n * k)
// Space Complexity: O(k)
int knapsackOptimised(vector<int> values, vector<int> weights, int k)
{
    int n = values.size();
    vector<int> prevDp(k + 1);
    vector<int> dp(k + 1);
    prevDp[0] = 0;
    for (int col = 1; col < k + 1; col++)
        prevDp[col] = 0;

    for (int row = 1; row < n + 1; row++)
    {
        dp[0] = 0;
        for (int col = 1; col < k + 1; col++)
        {
            if (col - weights[row - 1] >= 0)
                dp[col] = max(prevDp[col],
                              values[row - 1] + prevDp[col - weights[row - 1]]);
            else
                dp[col] = prevDp[col];
        }
        prevDp = dp;
        dp = vector<int>(k + 1);
    }
    return prevDp[k];
}

int main()
{
    vector<int> values = {20, 30, 15, 25, 10};
    vector<int> weights = {6, 13, 5, 10, 3};
    int k = 20;
    cout << knapsack(values, weights, k) << '\n';
    cout << knapsackOptimised(values, weights, k);
}