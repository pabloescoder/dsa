#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(nm)
// Space Complexity: O(n)
int ways(const vector<int> &jumps, int n, vector<int> &lookup)
{
    if (lookup[n] != -1)
        return lookup[n];

    if (n == 0)
    {
        lookup[n] = 1;
        return lookup[n];
    }

    int currJumps = 0;
    for (int i = 0; i < jumps.size(); i++)
    {
        if (n - jumps[i] >= 0)
            currJumps += ways(jumps, n - jumps[i], lookup);
    }
    lookup[n] = currJumps;
    return lookup[n];
}

int main()
{
    vector<int> jumps = {2, 4, 5, 8};
    int n = 10;
    vector<int> lookup(n + 1, -1);
    cout << ways(jumps, 10, lookup);
}