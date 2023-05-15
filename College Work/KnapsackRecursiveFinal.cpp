#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

int knapsackRecursive(vector<int> &weight, vector<int> &profit, int w, int n)
{
    if (w == 0 || n == 0)
        return 0;

    if (weight[n - 1] <= w)
        return max(profit[n - 1] + knapsackRecursive(weight, profit, w - weight[n - 1], n - 1), knapsackRecursive(weight, profit, w, n - 1));

    else
        return knapsackRecursive(weight, profit, w, n - 1);
}

int main()
{
    vector<int> profit = {15, 24, 82, 18, 43};
    vector<int> weight = {59, 67, 78, 10, 69};
    int w = 150;
    int n = profit.size();
    auto start = chrono::high_resolution_clock::now();
    cout << knapsackRecursive(weight, profit, w, n) << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Time: " << duration.count() << " ns";
    return 0;
}