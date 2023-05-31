#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n)
int rod(const vector<int> &prices, int remLength)
{
    int maxP = 0;
    if (remLength == 0)
        return 0;
    for (int i = 1; i <= remLength; i++)
    {
        int currP = prices[i] + rod(prices, remLength - i);
        maxP = max(currP, maxP);
    }
    return maxP;
}

int main()
{
    vector<int> prices = {0, 1, 3, 5, 6, 7, 9, 10, 11};
    cout << rod(prices, prices.size() - 1);
}