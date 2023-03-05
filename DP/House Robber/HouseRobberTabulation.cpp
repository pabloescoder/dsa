#include <iostream>
#include <algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n) <--- Can be optimised, see below
int maxRobbed(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int *dp = new int[n];
    dp[0] = arr[0];
    dp[1] = max(dp[0], arr[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    int res = dp[n - 1];
    delete[] dp;
    return res;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxRobbedOptimised(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int prevPrev = arr[0];
    int prev = max(prevPrev, arr[1]);
    for (int i = 2; i < n; i++)
    {
        int next = max(arr[i] + prevPrev, prev);
        prevPrev = prev;
        prev = next;
    }
    return prev;
}

int main()
{
    int arr[] = {2, 10, 3, 6, 8, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxRobbed(arr, n) << endl;
    cout << maxRobbedOptimised(arr, n);
}