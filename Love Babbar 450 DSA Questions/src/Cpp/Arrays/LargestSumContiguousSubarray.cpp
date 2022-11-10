// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

#include <iostream>
#include <algorithm> // for max()

// Kadane's Algorithm
// Given an array Arr[] of N integers.
// Find the contiguous sub-array(containing at least one number)
// which has the maximum sum and return its sum.
// Time Complexity: O(n)
// Space Complexity: O(1)
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum{arr[0]};
    long long currSum{arr[0]};
    for (int i = 1; i < n; i++)
    {
        currSum = max(static_cast<long long>(arr[i]), currSum + arr[i]);
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
    }

    return maxSum;
}

int main()
{
    int arr[]{1, 2, 3, -2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubarraySum(arr, n); // 9
}