#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n)
int subsets(vector<int> arr, int k, int i)
{
    if (k == 0)
        return 1;
    if (i == arr.size())
        return 0;

    if (arr[i] <= k)
        return subsets(arr, k - arr[i], i + 1) + subsets(arr, k, i + 1);
    else
        return subsets(arr, k, i + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 4};
    int k = 6;
    cout << subsets(arr, k, 0);
}