#include <iostream>
#include <algorithm> // fill_n
#include <vector>
using namespace std;

// Getting the memoized solution once we have the recursive one is very simple.
// Store the number of from (i, j) to (n, m) in lookup[i][j]
// If for any subproblem we have lookup[i][j], return that instead of calculating it again
// Otherwise do the whole recursive process like before and then store the answer in the lookup table then return that.
// Time Complexity = total number of subproblems * cost of 1 subproblem
// Total subproblems = {(0, 0), (0, 1), (1, 0), ... (n, m)} = n * m = nm
// Cost of 1 subproblem = O(1)
// Time Complexity = O(1) * nm = O(nm)
// Space Complexity = Space of recursive solution + Space for storing lookup table
//                  = O(n + m) + O(nm) = O(nm)

// Time Complexity = O(nm)
// Space Complexity = O(nm)
int paths(const vector<vector<int>> &matrix, int i, int j, int **lookup)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (lookup[i][j] != -1)
        return lookup[i][j];

    if (matrix[i][j] == 1)
    {
        lookup[i][j] = 0;
        return lookup[i][j];
    }

    if (i == n - 1 && j == m - 1)
    {
        lookup[i][j] = 1;
        return lookup[i][j];
    }

    if (i == n - 1)
        lookup[i][j] = paths(matrix, i, j + 1, lookup);
    else if (j == m - 1)
        lookup[i][j] = paths(matrix, i + 1, j, lookup);
    else
        lookup[i][j] = paths(matrix, i + 1, j, lookup) + paths(matrix, i, j + 1, lookup);
    return lookup[i][j];
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 1, 0, 1},
                                  {0, 0, 0, 0, 1},
                                  {0, 0, 1, 0, 0},
                                  {1, 0, 0, 0, 0}};
    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Printing Matrix\n";
    for (auto row : matrix)
    {
        for (auto elem : row)
        {
            cout << elem << " ";
        }
        cout << '\n';
    }

    // Creating Array of Pointers for memoization
    int **lookup = new int *[n];
    for (int i = 0; i < n; i++)
    {
        lookup[i] = new int[m];
        fill_n(lookup[i], m, -1);
    }

    cout << "Total Paths = " << paths(matrix, 0, 0, lookup); // 7

    // Cleanup
    for (int i = 0; i < n; i++)
        delete[] lookup[i];
    delete[] lookup;
    return 0;
}