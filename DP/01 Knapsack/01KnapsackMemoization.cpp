#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// For this problem, memoization sol is better than tabulation, because we do not have to solve all subproblems
// Whereas while filling the DP table, we do have to.
// Time Complexity: O(n * k)
// Space Complexity: O(n * k)
int knapsack(vector<int> values, vector<int> weights, int k, int n, vector<vector<int>> &lookup)
{
    if (n == values.size())
        return 0;
    if (lookup[k][n] != -1)
        return lookup[k][n];

    if (weights[n] <= k)
        lookup[k][n] = max(knapsack(values, weights, k, n + 1, lookup),
                           values[n] + knapsack(values, weights, k - weights[n], n + 1, lookup));
    else
        lookup[k][n] = knapsack(values, weights, k, n + 1, lookup);
    return lookup[k][n];
}

int main()
{
    vector<int> values = {20, 30, 15, 25, 10};
    vector<int> weights = {6, 13, 5, 10, 3};
    int k = 20;
    vector<vector<int>> lookup(k + 1, vector<int>(values.size() + 1, -1));
    cout << knapsack(values, weights, k, 0, lookup);
}