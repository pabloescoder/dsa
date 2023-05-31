// Reference: https://www.udemy.com/course/dynamic-programming-x/learn/lecture/28863260#questions
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int rod(const vector<int> &prices)
{
    int n = prices.size();
    vector<int> dp(n);
    dp[0] = prices[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i + 1; j++)
            dp[i] = max(dp[i], prices[j] + dp[i - j]);
    }
    return dp[n - 1];
}

int main()
{
    vector<int> prices = {0, 1, 3, 5, 6, 7, 9, 10, 11};
    cout << rod(prices);
}