#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(n * m) <--- Can be optimised, see below
bool inter(string &s1, string &s2, string &s3)
{
    int n = s1.size();
    int m = s2.size();
    if (n + m != s3.size())
        return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;
    for (int i = 1; i < n + 1; i++)
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    for (int j = 1; j < m + 1; j++)
        dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            bool check_s1 = s1[i - 1] == s3[i + j - 1] && dp[i - 1][j];
            bool check_s2 = s2[j - 1] == s3[i + j - 1] && dp[i][j - 1];
            dp[i][j] = check_s1 || check_s2;
        }
    }
    return dp[n][m];
}

// Time Complexity: O(n * m)
// Space Complexity: O(m)
bool interOptimised(string &s1, string &s2, string &s3)
{
    int n = s1.size();
    int m = s2.size();
    if (n + m != s3.size())
        return false;

    vector<bool> prevDp(m + 1);
    vector<bool> dp(m + 1);
    prevDp[0] = true;
    for (int j = 1; j < m + 1; j++)
        prevDp[j] = prevDp[j - 1] && s2[j - 1] == s3[j - 1];

    for (int i = 1; i < n + 1; i++)
    {
        dp[0] = prevDp[0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j < m + 1; j++)
        {
            bool check_s1 = s1[i - 1] == s3[i + j - 1] && prevDp[j];
            bool check_s2 = s2[j - 1] == s3[i + j - 1] && dp[j - 1];
            dp[j] = check_s1 || check_s2;
        }
        prevDp = dp;
        dp = vector<bool>(m + 1);
    }
    return prevDp[m];
}

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << boolalpha;
    cout << inter(s1, s2, s3) << endl;
    cout << interOptimised(s1, s2, s3);
}