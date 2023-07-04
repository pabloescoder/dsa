// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
#include <iostream>

// Given an array of positive integers. We need to make the given array a ‘Palindrome’.
// The only allowed operation is”merging” (of two adjacent elements).
// Merging two adjacent elements means replacing them with their sum.
// The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.
// To make any array a palindrome, we can simply apply merge operation n-1 times where n is the size of the array
// (because a single-element array is always palindromic, similar to single-character string).
// In that case, the size of array will be reduced to 1.
// But in this problem, we are asked to do it in the minimum number of operations.
// Examples:-
// Input : arr[] = {1, 4, 5, 1}
// Output : 1 (Merge 4 & 5)
// ----------------------------
// Input : arr[] = {15, 4, 15}
// Output : 0 (Already Palindrome)
// ----------------------------
// Input : arr[] = {11, 14, 15, 99}
// Output : 3 (Merge all elements, make an array of size 1, no other method possible)
// Time Complexity: O(N)
// Space Complexity: O(1)
using namespace std;

int minOpsToMakePalindrome(int arr[], int n)
{
    int start{0}, end{n - 1};
    int ops{0};
    while (start < end)
    {
        // If both elements at start and end are equal, no need to merge, start++, end--
        if (arr[start] == arr[end])
        {
            start++;
            end--;
        }
        else
        {
            // If element at end is greater, merge the two elements at start and start + 1
            if (arr[start] < arr[end])
            {
                arr[start + 1] += arr[start];
                ops += 1;
                start++;
            }
            // Else if element at start is greater, merge the two elements at end and end - 1
            else
            {
                arr[end - 1] += arr[end];
                ops += 1;
                end--;
            }
        }
    }
    return ops;
}

int main()
{
    int arr1[] = {1, 4, 5, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << minOpsToMakePalindrome(arr1, n1) << '\n'; // 1

    int arr2[] = {11, 14, 15, 99};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << minOpsToMakePalindrome(arr2, n2) << '\n'; // 3

    int arr3[] = {15, 4, 15};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << minOpsToMakePalindrome(arr3, n3) << '\n'; // 0
    return 0;
}