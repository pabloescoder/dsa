// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0

#include <iostream>
#include <algorithm> // for sort()

// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order without using any extra space.
// Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Approach
// Consider three pointers i = 0, j = 0 and k = arr1.length - 1
// While i <= k AND j <= arr2.length - 1
//     If arr1[i] < arr2[j]
//          Then increment i
//     Else
//          Swap arr1[k] and arr2[j]
//          Increment j
//          Decrement k
// Sort arr1 as well as arr2
// Time Complexity - O((n+m)log(n+m)) (n, m are the lengths of arr1 and arr2 respectively)
// Space Complexity - O(1)

using namespace std;
void swap(long long *a, long long *b);
void printArr(long long arr[], int n);

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i{0};
    int j{0};
    int k{n - 1};

    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(&arr2[j], &arr1[k]);
            j++;
            k--;
        }
    }

    // Sort the arrays to make them non decreasing
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    long long arr1[]{1, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    long long arr2[]{0, 2, 6, 8, 9};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Before:- \n";
    printArr(arr1, n);
    printArr(arr2, m);

    merge(arr1, arr2, n, m);
    cout << "After:- \n";
    printArr(arr1, n);
    printArr(arr2, m);
    return 0;

    // Output
    // Before:-
    // 1 3 5 7
    // 0 2 6 8 9
    // After:-
    // 0 1 2 3
    // 5 6 7 8 9
}

void swap(long long *a, long long *b)
{
    long long temp{*a};
    *a = *b;
    *b = temp;
}

void printArr(long long arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}