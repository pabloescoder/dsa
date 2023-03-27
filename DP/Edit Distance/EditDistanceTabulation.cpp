#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n) <--- Can be optimised, see below
int editDistance(const string &s1, const string &s2)
{
    if (s1.size() == 0 || s2.size() == 0)
        return max(s1.size(), s2.size());

    int n = s1.size();
    int m = s2.size();

    // +1 because the first cell in a row and first cell in a column is an empty string ''
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;

    // Filling first column, here str2 is an empty string, so we just increment the editDistance by 1 for each row
    // '' vs a = 1
    // '' vs ab = 2
    // '' vs abc = 3 and so on
    for (int row = 1; row < n + 1; row++)
        dp[row][0] = dp[row - 1][0] + 1; // or dp[row][0] = row;

    // Filling first row, same logic as above
    for (int col = 1; col < m + 1; col++)
        dp[0][col] = dp[0][col - 1] + 1; // or dp[0][col] = col;

    for (int row = 1; row < n + 1; row++)
    {
        for (int col = 1; col < m + 1; col++)
        {
            if (s1[row - 1] == s2[col - 1])
                dp[row][col] = dp[row - 1][col - 1];
            else
                dp[row][col] = 1 + min(
                                       min(dp[row][col - 1], dp[row - 1][col]),
                                       dp[row - 1][col - 1]);
        }
    }
    return dp[n][m];
}

// Time Complexity: O(m * n)
// Space Complexity: O(m)
int editDistanceOptimised(const string &s1, const string &s2)
{
    if (s1.size() == 0 || s2.size() == 0)
        return max(s1.size(), s2.size());

    int n = s1.size();
    int m = s2.size();

    vector<int> prevDp(m + 1);
    vector<int> dp(m + 1);

    prevDp[0] = 0;
    for (int col = 1; col < m + 1; col++)
        prevDp[col] = prevDp[col - 1] + 1; // or prevDp[col] = col;

    for (int row = 1; row < n + 1; row++)
    {
        dp[0] = prevDp[0] + 1; // or dp[0] = row
        for (int col = 1; col < m + 1; col++)
        {
            if (s1[row - 1] == s2[col - 1])
                dp[col] = prevDp[col - 1];
            else
                dp[col] = 1 + min(
                                  min(prevDp[col], dp[col - 1]),
                                  prevDp[col - 1]);
        }
        prevDp = dp;
        dp = vector<int>(m + 1);
    }
    return prevDp[m];
}

int main()
{
    string word1 = "inside";
    string word2 = "index";
    cout << editDistance(word1, word2) << '\n';
    cout << editDistanceOptimised(word1, word2);
}