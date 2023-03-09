#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// Time Complexity: O(mn)
// Space Complexity: O(mn)   <--- Can be optimised, see below
int lcs(const string &s1, const string &s2)
{
    int m = s1.size();
    int n = s2.size();

    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
        dp[i] = new int[n];

    dp[0][0] = (int)(s1[0] == s2[0]);

    // In the first row and first column, set 1 if the last char of both substrings match
    // Or if the previous cell in the corresponding row/column is 1
    for (int i = 1; i < m; i++)
        dp[i][0] = (int)(s1[i] == s2[0] || dp[i - 1][0]);
    for (int j = 1; j < n; j++)
        dp[0][j] = (int)(s2[j] == s1[0] || dp[0][j - 1]);

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    int ans = dp[m - 1][n - 1];

    // Cleanup
    for (int i = 0; i < m; i++)
        delete[] dp[i];
    delete[] dp;

    return ans;
}

// Time Complexity: O(mn)
// Space Complexity: O(n)
int lcsOptimised(const string &s1, const string &s2)
{
    int m = s1.size();
    int n = s2.size();

    int *prevPrev = new int[n];
    int *prev = new int[n];

    prevPrev[0] = (int)(s1[0] == s2[0]);
    for (int i = 1; i < n; i++)
        prevPrev[i] = (int)(s1[0] == s2[i] || prevPrev[i - 1]);
    for (int i = 1; i < m; i++)
    {
        prev[0] = (int)(s2[0] == s1[i] || prevPrev[0]);
        for (int j = 1; j < n; j++)
        {
            if (s1[i] == s2[j])
                prev[j] = 1 + prevPrev[j - 1];
            else
                prev[j] = max(prev[j - 1], prevPrev[j]);
        }
        delete[] prevPrev;
        prevPrev = prev;
        prev = new int[n];
    }

    int ans = prevPrev[n - 1];

    delete[] prevPrev;
    delete[] prev;
    return ans;
}

int main()
{
    string s1 = "abcde";
    string s2 = "ace";
    cout << lcs(s1, s2) << endl;
    cout << lcsOptimised(s1, s2);
}