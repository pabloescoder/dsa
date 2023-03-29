#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(k * n)
// Space Complexity: O(k * n)   <--- Can be optimised, see below
int subsets(vector<int> arr, int k, int i)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    for (int col = 1; col < k + 1; col++)
        dp[0][col] = 0;
    for (int row = 1; row < n + 1; row++)
        dp[row][0] = 1;

    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < k + 1; col++)
        {
            if (col - arr[row - 1] >= 0)
                dp[row][col] = dp[row - 1][col] + dp[row - 1][col - arr[row - 1]];
            else
                dp[row][col] = dp[row - 1][col];
        }
    }
    return dp[n][k];
}

// Time Complexity: O(k * n)
// Space Complexity: O(k)
int subsetsOptimised(vector<int> arr, int k, int i)
{
    int n = arr.size();
    vector<int> prevDp(k + 1);
    vector<int> dp(k + 1);
    prevDp[0] = 1;
    for (int col = 1; col < k + 1; col++)
        prevDp[col] = 0;

    for (int row = 1; row < n + 1; row++)
    {
        dp[0] = 1;
        for (int col = 1; col < k + 1; col++)
        {
            if (col - arr[row - 1] >= 0)
                dp[col] = prevDp[col] + prevDp[col - arr[row - 1]];
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
    vector<int> arr = {1, 2, 3, 1, 4};
    int k = 6;
    cout << subsets(arr, k, 0) << '\n';
    cout << subsetsOptimised(arr, k, 0);
}