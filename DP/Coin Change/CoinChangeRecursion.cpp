#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A is the amount, n is the size of the possible coins vector, for the worse case time complexity,
// we can assume that at every step the amount is being decreased only by 1, so worst case tree height = A
// and calls at each node = 2 (pick the coin or not pick), so 2^A calls,
// but we have n coins to pick from, so the overall complexity is n * 2^A
// Time Complexity: O(n * 2^A)
// Space Complexity: O(A)  // Worst case tree height = A assuming at each step A is being decreased only by 1
int coins(int amount, const vector<int> &poss_coins)
{
    if (amount == 0)
        return 0;

    else
    {
        int minC = INT_MAX;
        for (int i = 0; i < poss_coins.size(); i++)
        {
            if (amount >= poss_coins[i])
            {
                int currCoins = coins(amount - poss_coins[i], poss_coins);
                currCoins = (currCoins == INT_MAX) ? currCoins : currCoins + 1;
                minC = min(currCoins, minC);
            }
        }
        return minC;
    }
}

int main()
{
    int amount = 15;
    vector<int> possible_coins = {2, 3, 7};
    int minC = coins(amount, possible_coins);
    cout << ((minC == INT_MAX) ? -1 : minC);
}