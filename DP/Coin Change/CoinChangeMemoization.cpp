#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A is the amount, n is the size of the possible coins vector
// Time Complexity: O(A * n)
// Space Complexity: O(A)
int coins(int amount, const vector<int> &poss_coins, vector<int> &lookup)
{
    if (amount == 0)
        return 0;
    if (lookup[amount] != -1)
        return lookup[amount];

    else
    {
        int minC = INT_MAX;
        for (int i = 0; i < poss_coins.size(); i++)
        {
            if (amount >= poss_coins[i])
            {
                int currCoins = coins(amount - poss_coins[i], poss_coins, lookup);
                currCoins = (currCoins == INT_MAX) ? currCoins : currCoins + 1;
                minC = min(currCoins, minC);
            }
        }
        lookup[amount] = minC;
        return lookup[amount];
    }
}

int main()
{
    int amount = 15;
    vector<int> possible_coins = {2, 3, 7};
    vector<int> lookup(amount + 1, -1);
    int minC = coins(amount, possible_coins, lookup);
    cout << ((minC == INT_MAX) ? -1 : minC);
}