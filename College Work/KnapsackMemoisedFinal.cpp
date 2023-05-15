#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

int knapsackMemoised(vector<int> &weight, vector<int> &profit, int w, int n, vector<vector<int>> &lookup)
{
    if (w == 0 || n == 0)
        return 0;

    if (lookup[n][w] != -1)
        return lookup[n][w];

    if (weight[n - 1] <= w)
    {
        lookup[n][w] = max(profit[n - 1] + knapsackMemoised(weight, profit, w - weight[n - 1], n - 1, lookup), knapsackMemoised(weight, profit, w, n - 1, lookup));
        return lookup[n][w];
    }
    else
    {
        lookup[n][w] = knapsackMemoised(weight, profit, w, n - 1, lookup);
        return lookup[n][w];
    }
}

int main()
{
    vector<int> profit = {15, 24, 82, 18, 43};
    vector<int> weight = {59, 67, 78, 10, 69};
    int w = 150;
    int n = profit.size();
    vector<vector<int>> lookup(n + 1, vector<int>(w + 1, -1));
    auto start = chrono::high_resolution_clock::now();
    cout << knapsackMemoised(weight, profit, w, n, lookup) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time: " << duration.count() << " ns";
    return 0;
}