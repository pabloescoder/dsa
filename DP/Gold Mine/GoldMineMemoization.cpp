#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Total number of subproblems = m * n, time to solve each subproblem = O(1), so TC = m * n * O(1) = O(m*n)
// Space = Space of pure recursive + lookup size = O(n) + O(m * n) = O(m * n)

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
int maxGold(const vector<vector<int>> &mine, int i, int j, vector<vector<int>> &lookup)
{
    int n = mine.size();
    int m = mine[0].size();

    if (lookup[i][j] != -1)
        return lookup[i][j];

    if (i == n - 1) // Last row reached <- Base Case
        lookup[i][j] = mine[i][j];
    else if (i == 0 && j != 0 && j != m - 1) // First row, we can start from any cell
        lookup[i][j] = max(max(maxGold(mine, i, j + 1, lookup), mine[i][j] + maxGold(mine, i + 1, j - 1, lookup)),
                           mine[i][j] + max(maxGold(mine, i + 1, j, lookup), maxGold(mine, i + 1, j + 1, lookup)));
    else if (i == 0 && j == 0)
        lookup[i][j] = max(maxGold(mine, i, j + 1, lookup), mine[i][j] + max(maxGold(mine, i + 1, j, lookup), maxGold(mine, i + 1, j + 1, lookup)));
    else if (j == 0)
        lookup[i][j] = mine[i][j] + max(maxGold(mine, i + 1, j, lookup), maxGold(mine, i + 1, j + 1, lookup));
    else if (j == m - 1)
        lookup[i][j] = mine[i][j] + max(maxGold(mine, i + 1, j - 1, lookup), maxGold(mine, i + 1, j, lookup));
    else
        lookup[i][j] = mine[i][j] + max(maxGold(mine, i + 1, j - 1, lookup), max(maxGold(mine, i + 1, j, lookup), maxGold(mine, i + 1, j + 1, lookup)));
    return lookup[i][j];
}

// Same complexities as above but simpler approach
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
int maxGoldSimpler(const vector<vector<int>> &mine, int i, int j, vector<vector<int>> &lookup)
{
    int n = mine.size();
    int m = mine[0].size();

    if (i == n || j == -1 || j == m)
        return 0;

    if (lookup[i][j] == -1)
        lookup[i][j] = mine[i][j] + max(maxGoldSimpler(mine, i + 1, j - 1, lookup),
                                        max(maxGoldSimpler(mine, i + 1, j, lookup),
                                            maxGoldSimpler(mine, i + 1, j + 1, lookup)));
    return lookup[i][j];
}

int maxGoldSimplerCaller(const vector<vector<int>> &mine)
{
    int n = mine.size();
    int m = mine[0].size();

    // Same lookup will be used by all functions so that one subproblem will be solved only once
    vector<vector<int>> lookup(mine.size(), vector<int>(mine[0].size(), -1));

    int maxGold = INT_MIN;
    for (int col = 0; col < m; col++)
        maxGold = max(maxGoldSimpler(mine, 0, col, lookup), maxGold);
    return maxGold;
}

int main()
{
    vector<vector<int>> mine = {
        {3, 2, 12, 15, 10},
        {6, 19, 7, 11, 17},
        {8, 5, 12, 32, 21},
        {3, 20, 2, 9, 7},
    };

    vector<vector<int>> lookup(mine.size(), vector<int>(mine[0].size(), -1));
    cout << maxGold(mine, 0, 0, lookup) << '\n';
    cout << maxGoldSimplerCaller(mine);
}