#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n) <--- Can be optimised (see below)
int ways(const string &str)
{
    int n = str.size();

    if (str[0] == '0')
        return 0;
    else if (n == 1)
        return 1;

    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = (str[1] != '0') + (str[0] == '1' || str[0] == '2' && str[1] <= '6');

    for (int i = 2; i < n; i++)
    {
        if (str[i] != '0')
            dp[i] += dp[i - 1];
        if (str[i - 1] == '1' || str[i - 1] == '2' && str[i] <= '6')
            dp[i] += dp[i - 2];
    }
    return dp[n - 1];
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int waysOptimised(const string &str)
{
    int n = str.size();

    if (str[0] == '0')
        return 0;
    else if (n == 1)
        return 1;

    int prevDp = 1;
    int dp = (str[1] != '0') + (str[0] == '1' || str[0] == '2' && str[1] <= '6');
    int curr = 0;
    for (int i = 2; i < n; i++)
    {
        if (str[i] != '0')
            curr += dp;
        if (str[i - 1] == '1' || str[i - 1] == '2' && str[i] <= '6')
            curr += prevDp;
        prevDp = dp;
        dp = curr;
        curr = 0;
    }
    return dp;
}

int main()
{
    string str = "512810120129";
    cout << ways(str) << '\n';
    cout << waysOptimised(str);
}