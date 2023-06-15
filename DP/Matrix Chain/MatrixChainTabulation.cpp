#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
int chain(vector<pair<int, int>> &matrices)
{
    int n = matrices.size();
    vector<vector<int>> dp(matrices.size(), vector<int>(matrices.size()));
    for (int d = 1; d < n; d++)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i + d;
            int minSteps = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int leftCost = dp[i][k];
                int rightCost = dp[k + 1][j];
                int productCost = matrices[i].first * matrices[k].second * matrices[j].second;
                minSteps = min(minSteps, leftCost + rightCost + productCost);
            }
            dp[i][j] = minSteps;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<pair<int, int>> matrices = {{40, 20}, {20, 30}, {30, 10}, {10, 30}, {30, 50}};
    cout << chain(matrices);
}