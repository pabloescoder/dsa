#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(m * 2^n)  // n = num of steps, m = num of possible jumps
// Space complexity: O(n)
int ways(const vector<int> &jumps, int n)
{
    if (n == 0)
        return 1;

    int currWays = 0;
    for (int i = 0; i < jumps.size(); i++)
    {
        if (n - jumps[i] >= 0)
            currWays += ways(jumps, n - jumps[i]);
    }
    return currWays;
}

int main()
{
    vector<int> jumps = {2, 4, 5, 8};
    int n = 10;
    cout << ways(jumps, 10);
}