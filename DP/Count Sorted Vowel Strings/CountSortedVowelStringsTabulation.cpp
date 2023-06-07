#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n) <--- Can be optimised by using 1D dp and prevDp arrays
int count(int n)
{
    vector<vector<int>> dp(n, vector<int>(5));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
        dp[i][0] = 1;
    for (int j = 1; j < 5; j++)
        dp[0][j] = 1 + dp[0][j - 1];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < 5; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[n - 1][4];
}

int main()
{
    // int n = 2;
    int n = 9;
    cout << count(n);
}