#include <iostream>
#include <algorithm>
using namespace std;

// Space of non memoised fn = O(n) = call stack size
// So space of memoised fn = space(non memoised) + space(lookup table)
// = O(n) + O(n) = O(n)

// Time Complexity: O(n) // Total subproblems are n, time for each subproblem is O(1)
// Space Complexity: O(n)
int maxRobbed(int arr[], int i, int n, int *lookup)
{
    if (i >= n)
        return 0;
    if (i == n - 1)
        return arr[n - 1];

    if (lookup[i] != -1)
        return lookup[i];
    else
        lookup[i] = max(arr[i] + maxRobbed(arr, i + 2, n, lookup), maxRobbed(arr, i + 1, n, lookup));
    return lookup[i];
}

int main()
{
    int arr[] = {2, 10, 3, 6, 8, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *lookup = new int[n];
    fill_n(lookup, n, -1);
    cout << maxRobbed(arr, 0, n, lookup);
    delete[] lookup;
}