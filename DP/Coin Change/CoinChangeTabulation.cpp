#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(A * n)
// Space Complexity: O(A)
int coins(int amount, const vector<int> &poss_coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        int minC = INT_MAX;
        for (int j = 0; j < poss_coins.size(); j++)
        {
            if (i >= poss_coins[j])
            {
                int currCoins = dp[i - poss_coins[j]];
                currCoins = (currCoins == INT_MAX) ? currCoins : currCoins + 1;
                minC = min(currCoins, minC);
            }
        }
        dp[i] = minC;
    }
    return ((dp[amount] == INT_MAX) ? -1 : dp[amount]);
}

int main()
{
    int amount = 15;
    vector<int> possible_coins = {2, 3, 7};
    cout << coins(amount, possible_coins);
}