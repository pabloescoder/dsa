#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Getting the memoized function once you have the recursive solution is very simple.
// Check the recursive soln first if you haven't.
// For memoization, we will simply add a lookup table that will store the result of each subproblem.
// Here, the keys of the lookup table will be i, j
// So total elements stored in the lookup table will be m * n
// Now if the answer of the subproblem is not stored in the lookup table, we will first calculate and store it.
// Then we will return that value from the lookup table.

// Complexity Analysis
// i has values from {0, 1, 2, ... n - 1}
// j has values from {0, 1, 2, ..., m - 1}
// So total subproblems = (i, j) = {(0, 0), (0, 1), (1, 0), (1, 1), ... (n - 1, m - 1)}
//                      = n * m = nm
// Total Subproblems = nm
// Cost of each subproblem = 1
// So Time Complexity = nm O(1) = O(nm)
// For space, the space complexity is given by
// Space Complexity = Space complexity of non memoized + lookup table size
//                  = O(n + m) + O(nm)
// Therfore Space Complexity = O(nm)

// Time Complexity = O(nm)
// Space Complexity = O(nm)

int cost(const vector<vector<int>> &matrix, int i, int j, int **lookup)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (i == n - 1 && j == m - 1)
        return matrix[i][j];
    if (lookup[i][j] != -1)
        return lookup[i][j];

    if (i == n - 1)
        lookup[i][j] = matrix[i][j] + cost(matrix, i, j + 1, lookup);
    else if (j == m - 1)
        lookup[i][j] = matrix[i][j] + cost(matrix, i + 1, j, lookup);
    else
        lookup[i][j] = matrix[i][j] + min(cost(matrix, i + 1, j, lookup), cost(matrix, i, j + 1, lookup));

    return lookup[i][j];
}

int main()
{
    vector<vector<int>> matrix = {{3, 2, 12, 15, 10},
                                  {6, 19, 7, 11, 17},
                                  {8, 5, 12, 32, 21},
                                  {3, 20, 2, 9, 7}};

    int n = matrix.size();
    int m = matrix[0].size();

    int **lookup = new int *[n];
    for (int i = 0; i < n; i++)
    {
        lookup[i] = new int[m];
        fill_n(lookup[i], m, -1);
    }

    // Printing Output
    cout << "Printing Matrix\n";
    for (auto row : matrix)
    {
        for (auto elem : row)
        {
            cout << elem << " ";
        }
        cout << '\n';
    }

    // Note: cost(i, j) = cost from i,j to n-1,m-1. So we will start by calling cost(0,0)
    cout << "Minimum Cost = " << cost(matrix, 0, 0, lookup); // 52

    // Cleanup
    for (int i = 0; i < n; i++)
        delete[] lookup[i];
    delete[] lookup;

    return 0;
}