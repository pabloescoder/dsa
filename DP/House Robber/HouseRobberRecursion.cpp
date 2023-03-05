#include <iostream>
#include <algorithm>
using namespace std;

// Time complexity equation for the pure recursive approach is
// T(n) = T(n-1) + T(n-2) + c
// This is the same as TC for recursive fibonacci algo.
// This comes out to be O(phi^n)

// Time Complexity: O(phi^n) // Same as TC for recursive fibonacci
// Space Complexity: O(n) // At any point, max call stack size is O(n) == Height of recursion tree
int maxRobbed(int arr[], int i, int n)
{
    if (i >= n)
        return 0;
    if (i == n - 1)
        return arr[n - 1];

    return max(arr[i] + maxRobbed(arr, i + 2, n), maxRobbed(arr, i + 1, n));
}

int main()
{
    int arr[] = {2, 10, 3, 6, 8, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxRobbed(arr, 0, n);
}