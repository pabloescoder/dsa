#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(nm)
// Space Complexity: O(n)
int ways(const vector<int> &jumps, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int elem : jumps)
        {
            if (i - elem >= 0)
                dp[i] += dp[i - elem];
        }
    }
    return dp[n];
}

int main()
{
    vector<int> jumps = {2, 4, 5, 8};
    int n = 10;
    cout << ways(jumps, 10);
}