#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Complexity Analysis.
// In the worst recursive case we are calling the recursive fn twice. So number of subproblems = 2
// The length of a path in the matrix is n + m - 1. So we have n + m - 1 levels in the recursion tree.
// Each level has 2 subproblems (worst case), so we get 2 * 2 * 2 * 2 * 2 * ... 2^(n+m-1) total calls.
// So time complexity = O(2^(n + m))
// For space complexity. We aren't storing anything in the recursive functions and the matrix is provided by the main function
// So we just need to consider the space required by the recursive call stack.
// The total calls will be equal to the path length.
// So space complexity = O(n + m)

// Time Complexity: O(2^(n+m))
// Space Complexity: O(n + m)
// cost(i, j) = cost from i, j to n-1, m-1
int cost(const vector<vector<int>> &matrix, int i, int j)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Base Case. If we reached the end, then cost from end to end is the cost of the end cell
    if (i == n - 1 && j == m - 1)
        return matrix[i][j];

    if (i == n - 1) // There are no more rows left to traverse to
        return matrix[i][j] + cost(matrix, i, j + 1);
    else if (j == m - 1) // There are no more columns left to traverse to
        return matrix[i][j] + cost(matrix, i + 1, j);
    else
        return matrix[i][j] + min(cost(matrix, i + 1, j), cost(matrix, i, j + 1));
}

int main()
{
    vector<vector<int>> matrix = {{3, 2, 12, 15, 10},
                                  {6, 19, 7, 11, 17},
                                  {8, 5, 12, 32, 21},
                                  {3, 20, 2, 9, 7}};

    cout << "Printing Matrix\n";
    for (auto row : matrix)
    {
        for (auto elem : row)
        {
            cout << elem << " ";
        }
        cout << '\n';
    }

    // Note: cost(i, j) = cost from i,j to n-1,m-1. So we will start by calling cost(i,j)
    cout << "Minimum Cost = " << cost(matrix, 0, 0); // 52
    return 0;
}