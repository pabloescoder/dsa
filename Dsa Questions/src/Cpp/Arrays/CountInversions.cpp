// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include <iostream>

// Given an array of integers. Find the Inversion Count in the array.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
// If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Example
// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5
// has three inversions (2, 1), (4, 1), (4, 3).
using namespace std;

// Approach 1 - Using nested for loops (Brute Force)
// For each element arr[i], check all the elements after arr[i], if they are lesser than arr[i],
// Then increment inversion count by 1
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// NOTE: Code for this approach is NOT written because it is simple & has high time complexity.

long long int merge(long long arr[], const int start, const int mid, const int end);
long long int mergeSort(long long arr[], int start, int end);
// Approach 2 - Using modified merge sort
// https://www.youtube.com/watch?v=kQ1mJlwW-c0
// 1) The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step
//    until the base case is reached.
// 2) Create a function merge that counts the number of inversions when two halves of the array are merged,
// 3) Create two indices i and j, i is the index for the first half, and j is the index of the second half.
//      3.1) If a[i] is greater than a[j], then there are (mid – i) inversions. As left and right subarrays are sorted,
//           all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
// 4) Create a recursive function to divide the array into halves and find the answer by
//    summing the number of inversions in the first half, the second half and in the merge step.
// 5) The base case of recursion is when there is only one element in the given half.
// Time Complexity - O(nlogn)
// Space Complexity - O(n)

long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, static_cast<int>(N - 1));
}

int main()
{
    long long arr[]{1, 20, 6, 4, 5};
    long long n = sizeof(arr) / sizeof(arr[0]);
    cout << inversionCount(arr, n) << '\n'; // 5
    return 0;
}

long long int merge(long long arr[], const int start, const int mid, const int end)
{
    const int leftLen{mid - start + 1};
    const int rightLen{end - mid};

    long long *leftArr = new long long[leftLen];
    long long *rightArr = new long long[rightLen];

    for (int i = 0; i < leftLen; i++)
        leftArr[i] = arr[start + i];
    for (int i = 0; i < rightLen; i++)
        rightArr[i] = arr[mid + 1 + i];

    int leftP{0};
    int rightP{0};
    int arrP{start};
    long long int invCount{0};
    while (leftP < leftLen && rightP < rightLen)
    {
        if (leftArr[leftP] <= rightArr[rightP])
        {
            arr[arrP++] = leftArr[leftP++];
        }
        else
        {
            arr[arrP++] = rightArr[rightP++];
            invCount += (mid + 1) - (start + leftP);
        }
    }

    while (leftP < leftLen)
        arr[arrP++] = leftArr[leftP++];
    while (rightP < rightLen)
        arr[arrP++] = rightArr[rightP++];

    delete[] leftArr;
    delete[] rightArr;

    return invCount;
}

long long int mergeSort(long long arr[], const int start, const int end)
{
    long long int invCount{0};
    if (start < end)
    {
        int mid = (start + end) / 2;
        invCount += mergeSort(arr, start, mid);
        invCount += mergeSort(arr, mid + 1, end);
        invCount += merge(arr, start, mid, end);
    }
    return invCount;
}