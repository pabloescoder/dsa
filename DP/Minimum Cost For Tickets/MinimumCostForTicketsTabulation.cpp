#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// n = Last day
// Time Complexity: O(n)
// Space Complexity: O(n)
int cost(const vector<int> &trainDays, const vector<int> &costs, int n)
{
    vector<int> dp(n);
    unordered_set<int> days(trainDays.begin(), trainDays.end());
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1];
        if (days.count(i) != 0)
            dp[i] = min({costs[0] + dp[max(0, i - 1)],
                         costs[1] + dp[max(0, i - 7)],
                         costs[2] + dp[max(0, i - 30)]});
    }
    return dp[n - 1];
}

int main()
{
    vector<int> train_days = {1, 3, 8, 9, 22, 23, 28, 31};
    vector<int> costs = {4, 10, 25};
    int n = 32;
    cout << cost(train_days, costs, n);
}