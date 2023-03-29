#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n) <--- Can be optimised, see below
int scs(const string &str1, const string &str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 0;

    for (int row = 1; row < m + 1; row++)
        dp[row][0] = row;
    for (int col = 1; col < n + 1; col++)
        dp[0][col] = col;

    for (int row = 1; row < m + 1; row++)
    {
        for (int col = 1; col < n + 1; col++)
        {
            if (str1[row - 1] == str2[col - 1])
                dp[row][col] = dp[row - 1][col - 1] + 1;
            else
                dp[row][col] = 1 + min(dp[row][col - 1], dp[row - 1][col]);
        }
    }
    return dp[m][n];
}

// Time Complexity: O(m * n)
// Space Complexity: O(n)
int scsOptimised(const string &str1, const string &str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<int> prevDp(n + 1);
    vector<int> dp(n + 1);
    prevDp[0] = 0;

    for (int col = 1; col < n + 1; col++)
        prevDp[col] = col;

    for (int row = 1; row < m + 1; row++)
    {
        dp[0] = row;
        for (int col = 1; col < n + 1; col++)
        {
            if (str1[row - 1] == str2[col - 1])
                dp[col] = prevDp[col - 1] + 1;
            else
                dp[col] = 1 + min(dp[col - 1], prevDp[col]);
        }
        prevDp = dp;
        dp = vector<int>(n + 1);
    }
    return prevDp[n];
}

int main()
{
    string s1 = "abdacebfcab";
    string s2 = "acebfca";
    cout << scs(s1, s2) << endl;
    cout << scsOptimised(s1, s2);
}