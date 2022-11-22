// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
#include <iostream>
#include <unordered_set>

// Given an array of positive and negative numbers.
// Find if there is a subarray (of size at-least one) with 0 sum.
// Time Complexity: O(N)
// Space Complexity: O(N)

// Reference
// https://www.youtube.com/watch?v=PSpuM9cimxA
// Approach
// Let us consider array A = [4, 2, -3, 1, 6]
// If there is a subarray with sum 0,
// then the total sum till the end of the subarray will be equal to the total sum before the subarray
// In our example, sum till A[0] = sum till A[3]
// Sum till A[0] = 4 | Sum till A[3] = 4 + (2 + (-3) + 1) = 4 + 0 = 0
// So to solve using this approach, use an unordered_set to store the sum till that element
// If the sum is present in the set before inserting, then there is a zero sum subarray

using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> totalSums;
    int sumTillNow{0};
    for (int i = 0; i < n; i++)
    {
        sumTillNow += arr[i];
        if (sumTillNow == 0)
        {
            return true;
        }
        if (totalSums.count(sumTillNow) != 0)
        {
            return true;
        }
        else
        {
            totalSums.insert(sumTillNow);
        }
    }
    return false;
}

int main()
{
    int arr[]{4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << (subArrayExists(arr, n) ? "Yes" : "No"); // Yes
    return 0;
}