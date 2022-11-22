// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0
#include <iostream>
#include <algorithm>

// Given an array arr of size n and an integer X.
// Find if there's a triplet in the array which sums up to the given integer X.
// Example
// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1 (true)
// Explanation:
// The triplet {1, 4, 8} in
// the array sums up to 13.
using namespace std;
bool binarySearch(int arr[], int start, int n, int target);

// Approach 1 - Binary Search
// 1. Sort the array
// 2. Initialize remainingSum = X;
// 3. Iterate over every element arr[i] from i = 0 to i < n - 2
//      3.1. Subtract arr[i] from remainingSum
//      3.2. Iterate over every element arr[j] from j = i + 1 to j < n - 1
//             3.2.1. Subtract arr[j] from remainingSum
//             3.2.2. Now remainingSum will be equal to the required third no. of the triplet,
//                    Use binarySearch on the remaining portion of the array (j + 1 to n) and find remainingSum
//                    If found, return true, else add arr[j] again to remainingSum (to reset it)
//      3.3 If the program reaches here, the triplet was not yet found, so
//          Add arr[i] again to remainingSum to reset it.
// 4. If the program reaches here, no such triplet is present with sum X, return false.
// Time Complexity: O(N^2logN)
// Space Complexity: O(1)
bool hasTripletWithSumXUsingBinarySearch(int arr[], int n, int X)
{
    sort(arr, arr + n);
    int remainingSum{X};
    for (int i = 0; i < n - 2; i++)
    {
        remainingSum -= arr[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            remainingSum -= arr[j];
            if (binarySearch(arr, j + 1, n, remainingSum))
            {
                return true;
            }
            remainingSum += arr[j];
        }
        remainingSum += arr[i];
    }
    return false;
}

// Approach 2 - Two Pointer (More Optimised)
// 1. Sort the given array.
// 2. Loop over the array and fix the first element of the possible triplet, arr[i].
//      2.1 Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum,
//              If the sum is smaller than the required sum, increment the first pointer.
//              Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
//              Else, if the sum of elements at two-pointer is equal to given sum then return true and break.
// 3. If the program reaches here, no such triplet is present with sum X, return false.
// Time Complexity: O(N^2)
// Space Complexity: O(1)
bool hasTripletWithSumXUsingTwoPointer(int arr[], int n, int X)
{
    sort(arr, arr + n);
    // Now fix the first element one by one and find the other two elements
    for (int i = 0; i < n - 2; i++)
    {
        // To find the other two elements, start two index variables
        // from two corners of the array and move them toward each other
        int leftP{i + 1};
        int rightP{n - 1};

        while (leftP < rightP)
        {
            if (arr[i] + arr[leftP] + arr[rightP] == X)
                return true;
            else if (arr[i] + arr[leftP] + arr[rightP] < X)
                leftP++;
            else // arr[i] + arr[leftP] + arr[rightP] > sum
                rightP--;
        }
    }
    // If we reach here, then no triplet was found
    return false;
}

int main()
{
    int arr[]{1, 4, 45, 6, 10, 8};
    int arrCopy[]{1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 13;
    cout << (hasTripletWithSumXUsingBinarySearch(arr, n, X) ? "true" : "false") << '\n';
    cout << (hasTripletWithSumXUsingTwoPointer(arrCopy, n, X) ? "true" : "false") << '\n';
}

bool binarySearch(int arr[], int start, int n, int target)
{
    int s = start;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            return true;
    }
    return false;
}
