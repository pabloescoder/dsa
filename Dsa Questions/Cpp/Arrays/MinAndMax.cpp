// https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main()
{
    int arr[]{10, 20, 100, -20, 40, 50};
    int max{arr[0]};
    int min{arr[0]};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Array: ";
    printArray(arr, size);
    cout << "Min in arr: " << min << '\n';
    cout << "Max in arr: " << max << '\n';
    return 0;
}