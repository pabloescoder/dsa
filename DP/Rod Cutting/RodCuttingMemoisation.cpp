#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int rod(const vector<int> &prices, int remLength, vector<int> &lookup)
{
    int maxP = 0;
    if (remLength == 0)
        return 0;
    if (lookup[remLength] != -1)
        return lookup[remLength];
    for (int i = 1; i <= remLength; i++)
    {
        int currP = prices[i] + rod(prices, remLength - i, lookup);
        maxP = max(currP, maxP);
    }
    lookup[remLength] = maxP;
    if (remLength == prices.size() - 1)
        for (int elem : lookup)
            cout << elem << " ";
    return lookup[remLength];
}

int main()
{
    vector<int> prices = {0, 1, 3, 5, 6, 7, 9, 10, 11};
    vector<int> lookup(prices.size(), -1);
    cout << rod(prices, prices.size() - 1, lookup);
}