#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// At every node, we have max 2 decisions, pick or not pick
// In the worst case the weight k will decrease by only 1, making a max height of k (k = ks capacity)
// There are n such possible choices (n = size of values/weights array)
// Time Complexity: O(2^n)
// Space Complexity: O(n)
int knapsack(vector<int> values, vector<int> weights, int k, int n)
{
    if (n == values.size())
        return 0;

    if (weights[n] <= k)
        return max(knapsack(values, weights, k, n + 1),
                   values[n] + knapsack(values, weights, k - weights[n], n + 1));
    else
        return knapsack(values, weights, k, n + 1);
}

int main()
{
    vector<int> values = {20, 30, 15, 25, 10};
    vector<int> weights = {6, 13, 5, 10, 3};
    int k = 20;
    cout << knapsack(values, weights, k, 0);
}