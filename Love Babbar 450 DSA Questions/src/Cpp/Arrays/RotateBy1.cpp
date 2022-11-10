// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

#include <iostream>

// Given an array, rotate the array by one position in clock-wise direction.
// Time Complexity - O(n)
// Space Complexity - O(1)

using namespace std;
void printArr(const int arr[], const int n);

void rotate(int arr[], int n)
{
    int last = arr[n - 1];
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main()
{
    int arr[]{10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before: ";
    printArr(arr, n);

    rotate(arr, n);
    cout << "After: ";
    printArr(arr, n);
    return 0;

    // Output
    // Before: 10 20 30 40 50
    // After: 50 10 20 30 40
}

void printArr(const int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}