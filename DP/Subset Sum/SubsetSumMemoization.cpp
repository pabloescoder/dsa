#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(k * n)
// Space Complexity: O(k * n)
int subsets(vector<int> arr, int k, int i, vector<vector<int>> &lookup)
{
    if (k == 0)
        return 1;
    if (i == arr.size())
        return 0;
    if (lookup[k][i] != -1)
        return lookup[k][i];

    if (arr[i] <= k)
        lookup[k][i] = subsets(arr, k - arr[i], i + 1, lookup) + subsets(arr, k, i + 1, lookup);
    else
        lookup[k][i] = subsets(arr, k, i + 1, lookup);
    return lookup[k][i];
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 4};
    int k = 6;
    vector<vector<int>> lookup(k + 1, vector<int>(arr.size(), -1));
    cout << subsets(arr, k, 0, lookup);
}