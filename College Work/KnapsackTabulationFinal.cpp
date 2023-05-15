#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

int knapsackTabulation(vector<int> &weight, vector<int> &profit, int w, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

    // // Initialisation
    // for (int i = 0; i < n + 1; i++)
    //     dp[i][0] = 0;
    // for (int j = 0; j < w + 1; j++)
    //     dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++) // For number of rows
    {
        for (int j = 1; j < w + 1; j++) // For number of columns
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
    vector<int> profit = {15, 24, 82, 18, 43};
    vector<int> weight = {59, 67, 78, 10, 69};
    int w = 150;
    int n = profit.size();
    auto start = chrono::high_resolution_clock::now();
    cout << knapsackTabulation(weight, profit, w, n) << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Time: " << duration.count() << " ns";
}