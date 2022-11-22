// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
#include <iostream>

// Given an array of positive and negative numbers, arrange them in an alternate fashion such that
// every positive number is followed by a negative and vice-versa maintaining the order of appearance.
// The number of positive and negative numbers need not be equal.
// If there are more positive numbers they appear at the end of the array.
// If there are more negative numbers, they too appear at the end of the array.
// Examples
// Input:  arr[] = {1, 2, 3, -4, -1, 4}
// Output: arr[] = {-4, 1, -1, 2, 3, 4}
// ----
// Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
// Output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
// Use O(1) extra space
// Time Complexity: O(N^2)  |  Traversal O(N), Rotating O(N), Rotating is nested inside traversal
// Space Complexity: O(1)
// Coded below (My Approach - Two Pointer)
// Similar Approach - https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/#:~:text=order%20of%20appearances.-,Optimal%20Approach%3A

// NOTE: If we were allowed to use extra space, the question becomes easier.
// Approach (If extra space was allowed):
// Use 2 data structures (vector) to store negative and positive elements respectively
// Fill the array with alternating elements, if one vector has no more elements, fill all elements from remaining.
// Time Complexity: O(N)
// Space Complexity: O(N)
// NOTE: Not coded since the question asks for O(1) space solution

using namespace std;
void rotateArr(int arr[], int start, int end);
void printArr(int arr[], int n);

void makeAlternating(int arr[], int n)
{
    int posP{0};
    int negP{0};

    // Initially findingPos is false because we want the final array to start with a negative number
    bool findingPos = false;
    while (posP < n && negP < n)
    {
        // posP will point to next positive number
        while (arr[posP] < 0)
            posP++;

        // negP will point to next negative number
        while (arr[negP] >= 0)
            negP++;

        if (!findingPos)
        {
            // If we are finding a negative number and negP < posP then no rotation is needed
            // Because negative number appears before positive number
            if (negP < posP)
                negP++;
            // Otherwise rotate right the subarray to bring negP to the start and push other elements one index ahead
            // After rotating increment negP and set posP to negP because we have placed those numbers in the correct location
            // So no need to look at them again
            else
            {
                rotateArr(arr, posP, negP);
                negP = ++posP;
            }
            findingPos = true;
        }

        // Similar to what we did above but here we are finding a positive number.
        else
        {
            if (posP < negP)
                posP++;
            else
            {
                rotateArr(arr, negP, posP);
                posP = ++negP;
            }
            findingPos = false;
        }
    }
}

int main()
{
    int arr1[]{1, 2, 3, -4, -1, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printArr(arr1, n1); // 1 2 3 -4 -1 4
    makeAlternating(arr1, n1);
    printArr(arr1, n1); // -4 1 -1 2 3 4

    cout << '\n';

    int arr2[]{-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printArr(arr2, n2); // -5 -2 5 2 4 7 1 8 0 -8
    makeAlternating(arr2, n2);
    printArr(arr2, n2); // -5 5 -2 2 -8 4 7 1 8 0

    cout << '\n';

    int arr3[]{-5, -2, -5, -4, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printArr(arr3, n3); // -5 -2 -5 -4 7
    makeAlternating(arr3, n3);
    printArr(arr3, n3); // -5 7 -2 -5 -4
    return 0;
}

void rotateArr(int arr[], int start, int end)
{
    int lastElement = arr[end];
    for (int i = end; i > start; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = lastElement;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
