// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0
#include <iostream>

// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.
// If such a subarray do not exist return 0 in that case.
// Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).
using namespace std;

// Approach - Sliding Window
// 1. Create two pointer variables, startP=0, endP=0, and initialize currentSum = 0, minSubLen = n + 1 (initially).
// 2. While endP < n, do:
//      2.1. While currSum <= x && endP < n, do: update currentSum by adding element at endP, currentSum = currentSum + arr[endP], increment endP.
//      2.2. If the sum has exceeded, subtract until sum < x, increment startP and update minSubLen if required
// 3. Return minSubLen
// Time Complexity: O(N)
// Auxiliary Space: O(1)
// Note: This approach doesn't work if array has negative numbers, for that check https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
int smallestSubWithSum(int arr[], int n, int x)
{
    int startP{0}, endP{0};
    int minSubLen{n + 1};
    int currSum{0};

    while (endP < n)
    {
        // Keep adding elements until sum is LTE x
        while (currSum <= x && endP < n)
            currSum += arr[endP++];

        // If the sum has exceeded, subtract until sum < x and update minSubLen if required
        while (currSum > x && startP < n)
        {
            if (endP - startP < minSubLen)
            {
                minSubLen = endP - startP;
            }
            currSum -= arr[startP++];
        }
    }
    return minSubLen;
}

int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << smallestSubWithSum(arr1, n1, x); // 3
}