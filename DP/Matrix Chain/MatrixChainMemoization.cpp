#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
int chain(vector<pair<int, int>> &matrices, int i, int j, vector<vector<int>> &lookup)
{
    if (i == j)
        return 0;
    if (lookup[i][j] != -1)
        return lookup[i][j];

    int minSteps = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int currSteps = matrices[i].first * matrices[k].second * matrices[j].second;
        minSteps = min(minSteps, currSteps + chain(matrices, i, k, lookup) + chain(matrices, k + 1, j, lookup));
    }
    lookup[i][j] = minSteps;
    return lookup[i][j];
}

int main()
{
    vector<pair<int, int>> matrices = {{40, 20}, {20, 30}, {30, 10}, {10, 30}, {30, 50}};
    vector<vector<int>> lookup(matrices.size(), vector<int>(matrices.size(), -1));
    cout << chain(matrices, 0, matrices.size() - 1, lookup);
}