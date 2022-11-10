// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Reference:-
// https://www.youtube.com/watch?v=29uyA4F9t5I
#include <iostream>
#include <algorithm>
using namespace std;
// Given an array arr[] denoting heights of N towers and a positive integer K.
// For each tower, you must perform exactly one of the following operations exactly once.
// Increase the height of the tower by K OR Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.
// Note: It is compulsory to increase or decrease the height by K for each tower.
// After the operation, the resultant array should not contain any negative integers.

// Approach:-
// Sort the array
// Assume that there is a point (a point is BETWEEN 2 elements in the array),
// On the left of the point, add k to all the elements.
// On the right of the point, subtract k from all the elements.
// Check for each possible point in the array.
// Time Complexity: O(NlogN)
// Space Complexity: O(logN)

// Approach - Additional Details
// Our array has 2 segments after following the above approach,
// (A[0]+k, A[1]+k, ..., A[i]+k, A[i+1]-k, A[i+2]-k, ..., A[n]-k)      (n = Array length)
// The first segment (in which we added k) is to the left of our point, A[i]+k is the last element of the first segment
// The second segment (in which we subtracted k) is to the right of the point, A[i+1]-k is the first element of the second segment

// For the first segment, the smallest element is left (left = A[0]+k) and the largest is A[i]+k
// For the second segment, the smallest element is A[i+1] - k, the largest is right (right = A[n]-k)
// So, for each point, the largest element should be either A[i]+k OR right
// Similarly, the smallest element should be either A[i+1]-k OR left

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int maxH{};
    int minH{};
    int difference{arr[n - 1] - arr[0]};
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= k)
        {
            maxH = max(arr[i - 1] + k, arr[n - 1] - k);
            minH = min(arr[i] - k, arr[0] + k);
            difference = min(difference, maxH - minH);
        }
    }
    return difference;
}

int main()
{
    int arr[]{2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    cout << getMinDiff(arr, n, 5); // 7
}