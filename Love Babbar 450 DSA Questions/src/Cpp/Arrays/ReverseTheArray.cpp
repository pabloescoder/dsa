#include <iostream>
using namespace std;

void swap(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void reverseArray(int arr[], int size)
{
    int start{0};
    int end{size - 1};
    while (start < end)
    {
        swap(arr, start, end);
        start++;
        end--;
    }
}

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
    int arr[]{10, 20, 40, 30};
    int size{sizeof(arr) / sizeof(arr[0])};
    cout << "Initial Array:- " << '\n';
    printArray(arr, size);
    cout << "Reversed Array:- " << '\n';
    reverseArray(arr, size);
    printArray(arr, size);
    return 0;
}