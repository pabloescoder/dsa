// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0
#include <iostream>
#include <unordered_set>
#include <unordered_map>

// Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not.
// Both the arrays are not in sorted order.
// It may be assumed that elements in both arrays are distinct.
// Note: What will you do when elements in both arrays are NOT distinct?
using namespace std;

// Approach 1 - Unordered Set (Only works when both arrays are distinct)
// 1. Add all the elements of the first (bigger) array to a unordered_set
// 2. For every element arr2[i] of the second array, check if that element is present in the set
// 3. If any element is not present, return false, otherwise if the loop finishes whithout returning, return true
// Time Complexity: O(M + N)
// Space Complexity: O(M) (M is the size of the larger array - arr1[])
// NOTE: DOES NOT WORK when either array has repeating elements.
// Alternatively, add all the elements of both arrays in the same set using a for loop.
// If the length of the final set is greater than the length of arr1[] (bigger array), then return false else true.
bool isSubsetUsingUnorderedSet(int arr1[], int arr2[], int m, int n)
{
    unordered_set<int> mainSet;
    for (int i = 0; i < m; i++)
        mainSet.insert(arr1[i]);

    for (int i = 0; i < n; i++)
    {
        if (mainSet.count(arr2[i]) == 0)
            return false;
    }
    return true;
}

// Approach 2 - Unordered Maps (Always works)
// 1. Store the frequency count of all the elements of the first (larger) array in a unordered_map
// 2. For every element arr2[i] of the second array,
//    // 2.1 if that element (key) is present in map, decrease its frequency (value) by 1
//    // 2.2 If that element is not present, return false
// 3. If the loop finishes whithout returning, return true
// Time Complexity: O(M + N)
// Space Complexity: O(M) (M is the size of the larger array - arr1[])
// NOTE: WORKS EVEN when either array has repeating elements.
bool isSubsetUsingUnorderedMap(int arr1[], int arr2[], int m, int n)
{
    unordered_map<int, int> freqMap;
    for (int i = 0; i < m; i++)
        freqMap[arr1[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (freqMap[arr2[i]] > 0)
            freqMap[arr2[i]]--;
        else
            return false;
    }
    return true;
}

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << (isSubsetUsingUnorderedSet(arr1, arr2, m, n) ? "Yes" : "No") << '\n'; // Yes

    // Repeating elements, arr4 has two 1s and arr3 has one 1. Should return No.
    int arr3[] = {11, 1, 13, 21, 3, 7};
    int arr4[] = {11, 1, 3, 7, 1};
    int m1 = sizeof(arr3) / sizeof(arr3[0]);
    int n1 = sizeof(arr4) / sizeof(arr4[0]);
    cout << (isSubsetUsingUnorderedMap(arr3, arr4, m1, n1) ? "Yes" : "No") << '\n'; // No
}