#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Every node can make a max of 3 recursive calls (except the first row nodes that make 4 calls)
// And max height of the recursive tree is m + n
// At any point of time, there will be a max of m + n recursive calls on the call stack

// Time Complexity: O(3^(m + n)) <--- Can be improved, see below
// Space Complexity: O(m + n)
int maxGold(const vector<vector<int>> &mine, int i, int j)
{
    int n = mine.size();
    int m = mine[0].size();

    if (i == n - 1) // Last row reached <- Base Case
        return mine[i][j];
    else if (i == 0 && j != 0 && j != m - 1) // First row, we can start from any cell
        return max(max(maxGold(mine, i, j + 1), mine[i][j] + maxGold(mine, i + 1, j - 1)),
                   mine[i][j] + max(maxGold(mine, i + 1, j), maxGold(mine, i + 1, j + 1)));
    else if (i == 0 && j == 0)
        return max(maxGold(mine, i, j + 1), mine[i][j] + max(maxGold(mine, i + 1, j), maxGold(mine, i + 1, j + 1)));
    else if (j == 0)
        return mine[i][j] + max(maxGold(mine, i + 1, j), maxGold(mine, i + 1, j + 1));
    else if (j == m - 1)
        return mine[i][j] + max(maxGold(mine, i + 1, j - 1), maxGold(mine, i + 1, j));
    else
        return mine[i][j] + max(maxGold(mine, i + 1, j - 1), max(maxGold(mine, i + 1, j), maxGold(mine, i + 1, j + 1)));
}

// ---------------------------------------------------------------------------------------------------
// Every node makes 3 recursive calls
// And max height of the recursive tree is n because we are incrementing column by 1 for each rec call
// At any point of time, there will be a max of n recursive calls on the call stack
// maxGoldOptimised(mine, 0, 0) will give max if started from cell 0 in row 0
// maxGoldOptimised(mine, 0, 1) will give max if started from cell 1 in row 0
// We can start from any cell in row 0, so call it m times with j = 0 to j = m

// Time Complexity = O(m * 3^n)
// Space Complexity = O(n)
int maxGoldOptimised(const vector<vector<int>> &mine, int i, int j)
{
    int n = mine.size();
    int m = mine[0].size();

    if (i == n || j == -1 || j == m)
        return 0;
    return mine[i][j] + max(maxGoldOptimised(mine, i + 1, j - 1),
                            max(maxGoldOptimised(mine, i + 1, j),
                                maxGoldOptimised(mine, i + 1, j + 1)));
}

int maxGoldOptimisedCaller(const vector<vector<int>> &mine)
{
    int n = mine.size();
    int m = mine[0].size();

    int maxGold = INT_MIN;
    for (int col = 0; col < m; col++)
        maxGold = max(maxGoldOptimised(mine, 0, col), maxGold);
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
    cout << maxGold(mine, 0, 0);
    cout << '\n';
    cout << maxGoldOptimisedCaller(mine);
}