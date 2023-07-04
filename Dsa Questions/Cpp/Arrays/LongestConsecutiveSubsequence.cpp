// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
#include <iostream>
#include <unordered_set>
#include <algorithm> // For max

// Given an array of positive integers. Find the length of the longest sub-sequence
// such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
// Example
// a[] = {2,6,1,9,4,5,3}
// Output: 6
// Explanation:
// The consecutive numbers here are 1, 2, 3, 4, 5, 6.
// These 6 numbers form the longest consecutive subsquence.
using namespace std;

// Approach 1 - Naive
// Sort the array
// Find the longest subsequence by looping over the sorted array
// Not coded here
// Time Complexity: O(NlogN)
// Space Complexity: O(logN)

// Approach 2 - Using unordered_set
// Reference: https://www.youtube.com/watch?v=qgizvmgeyUM
// Step 1: First we will traverse through the array and add all the elements in the set <--- O(N)
// Now one thing that is important to understand is
// If we have an array that has the largest subsequence as 1, 2, 3, 4
// Then when we iterate over it, and we are at say 2, it will be a waste of time to check if 3 and 4 exist
// Similarly if we are at 3, or 4 then it will be a waste of time to check if 4 and 5 exist respectively
// If we keep checking for every number in the array then the complexity will become O(N^2)
// Instead we will check for subsequent numbers ONLY when we are at the smallest number in the subsequence
// So, if arr[i] - 1 exists in the set, continue, BUT if it doesn't exist, then check for subsequent elements.
// Step 2: If we are at the smallest number in the subsequence, use another loop to check for subsequent elements
// Step 3: Find all such subsequence lengths and return the maximum length
// Traversing the array for a second time <--- O(N), Checking for subsequent elements, at max <--- O(N)
// Time Complexity: O(3N) == O(N)
// Space Complexity: O(N) <--- storing elements in the set
int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int> arrSet;
    for (int i = 0; i < N; i++)
    {
        arrSet.insert(arr[i]);
    }

    int currSubLen{1};
    int maxSubLen{1};
    for (int i = 0; i < N; i++)
    {
        // If current element is the smallest number in the subsequence, find subsequent elements
        if (arrSet.count(arr[i] - 1) == 0)
        {
            int nextElement = arr[i] + 1;
            while (arrSet.count(nextElement) != 0)
            {
                currSubLen += 1;
                nextElement += 1;
            }
            maxSubLen = max(maxSubLen, currSubLen);
            currSubLen = 1; // Reset current subsequence length for next subsequence
        }

        // If current element is not the smallest element in the subsequence, do nothing
        // Following statement is redundant and can be removed, but is kept for clarity
        else
        {
            continue;
        }
    }
    return maxSubLen;
}

int main()
{
    int arr[]{1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // 4 <--- Longest consecutive subsequence = [1, 2, 3, 4]
    cout << findLongestConseqSubseq(arr, n);
}