#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// For Tabulation, the solution is iterative.
// Initially we will start with an array dp[n][m] where dp[i][j] represents the cost to traverse from 0,0 to i,j
// Note that this is opposite to what we did for memoization.
// In memoization cost(i,j) = cost from (i, j) to (n-1, m-1)
// In tabulation dp(i, j) = cost from (0, 0) to (i, j)
// This is done so that we can fill the dp matrix from left to right, top to bottom. It's more intuitive.
// So the shortest subproblem in tabulation will be dp[0][0] (cost from (0,0) to (0, 0)) = matrix[0][0]
// Then for every element at index i,j in dp, the user can come from the top or the left
// So dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i][j-1])
// And the edge cases will be in the top row, where we there's nothing above to come from
// And the leftmost column where theres nothing in the left to come from

// Complexity Analysis (Non space optimised tabulation)
// Time Complexity = O(nm) ---> Nested for loop n * m
// Space Complexity = O(nm) ---> dp array dp[n][m] ---> Can be optimised, see below
int cost(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Creating dp array to store the tabulated values ---> dp[n][m]
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[m];
    }

    dp[0][0] = matrix[0][0]; // Shortest subproblem

    for (int j = 1; j < m; j++) // Filling the top row (Edge case)
        dp[0][j] = matrix[0][j] + dp[0][j - 1];

    for (int i = 1; i < n; i++) // Filling the leftmost column (Edge case)
        dp[i][0] = matrix[i][0] + dp[i - 1][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // For every element at index i,j in dp, the user can come from the top or the left
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int res = dp[n - 1][m - 1];

    // Cleanup
    for (int i = 0; i < n; i++)
        delete[] dp[i];
    delete[] dp;

    return res;
}

// Now if we see the above tabulation approach, we notice that for calculating every index i, j
// We just need the top element and left element ie. (i-1, j) and (i, j-1)
// So there is no need to store the whole n*m dp 2D array
// We can instead just store 2 rows prevDp and dp.
// prevDp is the row i - 1
// And dp is initially empty, and is then filled by our logic of coming from the top and the left just like we did until now
// And at the end of every iteration, prevDp becomes dp and dp becomes empty and is filled again
// Repeat until we reach the end and then return prevDp[m-1] (because dp is stored in prevDp and made empty)

// Complexity Analysis
// Time Complexity: O(nm) ---> Nested for loops n * m
// Space Complexity: O(2m) = O(m) ---> 2 arrays of length m
int costSpaceOptimised(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Create the 2 arrays to store the 2 rows
    int *prevDp = new int[m];
    int *dp = new int[m];

    prevDp[0] = matrix[0][0];
    for (int j = 1; j < m; j++) // Fill prevDp initially just like we did for the top row edge case above
        prevDp[j] = matrix[0][j] + prevDp[j - 1];

    for (int i = 1; i < n; i++)
    {
        dp[0] = matrix[i][0] + prevDp[0]; // There is nothing to the left to come from
        for (int j = 1; j < m; j++)
        {
            // For every element at index j in dp, the user can come from the top (prevDp[j]) or the left (dp[j-1])
            dp[j] = matrix[i][j] + min(prevDp[j], dp[j - 1]);
        }
        delete[] prevDp;
        prevDp = dp;
        dp = new int[m];
    }

    int res = prevDp[m - 1];

    // Cleanup
    delete[] prevDp;
    delete[] dp;

    return res;
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

    cout << "Minimum Cost = " << cost(matrix) << '\n';                         // 52
    cout << "Minimum Cost (Space Optimised) = " << costSpaceOptimised(matrix); // 52
    return 0;
}