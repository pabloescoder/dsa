// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void swap(int *a, int *b);
void printArr(int arr[], int n);

void sort012(int arr[], int n)
{
    // P = Pointer
    int zeroP{0};
    int oneP{0};
    int twoP{n - 1};

    while (oneP < twoP)
    {
        if (arr[oneP] == 0)
        {
            swap(&arr[zeroP], &arr[oneP]);
            zeroP++;
            oneP++;
        }
        else if (arr[oneP] == 2)
        {
            swap(&arr[oneP], &arr[twoP]);
            twoP--;
        }
        else
        {
            oneP++;
        }
    }
}

int main()
{
    int arr[]{1, 1, 0, 2, 1, 0, 2, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before: ";
    printArr(arr, n);

    sort012(arr, n);
    cout << "After: ";
    printArr(arr, n);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int n)
{
    cout << "Printing array elements:- \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}