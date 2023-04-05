#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int lis(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int maxL = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                maxL = max(maxL, dp[j]);
            dp[i] = maxL + 1;
        }
    }
    return dp[n - 1];
}

int main()
{
    vector<int> arr = {7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7};
    cout << lis(arr) << '\n';
    vector<int> arr2 = {8, 5, 5, 3};
    cout << lis(arr2) << '\n';
}