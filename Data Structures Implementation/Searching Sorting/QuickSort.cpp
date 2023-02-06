#include <iostream>
using namespace std;

void printArr(int *arr, int n);

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int main()
{
    int arr[] = {1, 7, 2, 9, 10, 0, 50, -10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    quickSort(arr, 0, n - 1);
    printArr(arr, n);
}

void printArr(int *arr, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ((i == n - 1) ? " " : ", ");
    }
    cout << "]\n";
}