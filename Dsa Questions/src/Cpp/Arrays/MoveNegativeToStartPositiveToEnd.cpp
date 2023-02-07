// An array contains both positive and negative numbers in random order.
// Rearrange the array elements so that all negative numbers appear before all positive numbers.
// Order of elements is not important here.

#include <iostream>
using namespace std;

void swap(int *a, int *b);
void printArr(int arr[], int n);

// Approach 1 - Two Pointer approach
// Order of negative & positive numbers corresponding to input array is NOT maintained
// Time Complexity: O(n)
// Space Complexity: O(1)
void move(int arr[], int n)
{
    // P = Pointer
    int negP{0};
    int posP{n - 1};
    while (negP < posP)
    {
        if (arr[negP] >= 0)
        {
            swap(&arr[negP], &arr[posP]);
            posP--;
        }
        else
        {
            negP++;
        }
    }
}

int main()
{
    int arr[]{-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before: ";
    printArr(arr, n);

    move(arr, n);
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