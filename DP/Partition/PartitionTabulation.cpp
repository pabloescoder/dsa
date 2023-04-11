#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n * (sum(n) / 2)) == O(n * sum(n))
// Space Complexity: O(n * (sum(n) / 2)) == O(n * sum(n))  <--- Can be optimised (see below)
bool partition(const vector<int> &arr)
{
    int n = arr.size();
    int total = 0;
    for (int elem : arr)
        total += elem;
    if (n == 1 || total % 2 != 0)
        return false;

    vector<vector<int>> dp(n, vector<int>((total / 2) + 1));
    for (int col = 0; col < (total / 2) + 1; col++)
        dp[0][col] = arr[0] == col;
    for (int row = 0; row < n; row++) // Not necessary as by default it is 0
        dp[row][0] = 0;

    for (int row = 1; row < n; row++)
    {
        for (int col = 1; col < (total / 2) + 1; col++)
        {
            if (col - arr[row] >= 0)
                dp[row][col] = dp[row - 1][col] || dp[row - 1][col - arr[row]];
            else
                dp[row][col] = dp[row - 1][col];
        }
    }
    return dp[n - 1][total / 2];
}

// Time Complexity: O(n * (sum(n) / 2)) == O(n * sum(n))
// Space Complexity: O((sum(n) / 2)) == O(sum(n))
bool partitionOptimised(const vector<int> &arr)
{
    int n = arr.size();
    int total = 0;
    for (int elem : arr)
        total += elem;
    if (n == 1 || total % 2 != 0)
        return false;

    vector<int> prevDp((total / 2) + 1);
    vector<int> dp((total / 2) + 1);
    for (int col = 0; col < (total / 2) + 1; col++)
        prevDp[col] = arr[0] == col;

    for (int row = 1; row < n; row++)
    {
        dp[0] = 0;
        for (int col = 1; col < (total / 2) + 1; col++)
        {
            if (col - arr[row] >= 0)
                dp[col] = prevDp[col] || prevDp[col - arr[row]];
            else
                dp[col] = prevDp[col];
        }
        prevDp = dp;
        dp = vector<int>((total / 2) + 1);
    }
    return prevDp[total / 2];
}

int main()
{
    cout << boolalpha;
    vector<int> arr = {4, 5, 3, 2, 5, 1};
    cout << partition(arr) << '\n';
    cout << partitionOptimised(arr) << '\n';

    arr = {5, 6, 2, 3, 8, 1};
    cout << partition(arr) << '\n';
    cout << partitionOptimised(arr);
}