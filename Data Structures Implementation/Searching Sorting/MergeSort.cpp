#include <iostream>
using namespace std;

void printArr(int *arr, int n);

void merge(int *arr, int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    int *left = new int[leftSize];
    int *right = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[start + i];
    for (int i = 0; i < rightSize; i++)
        right[i] = arr[mid + 1 + i];

    int leftP = 0;
    int rightP = 0;
    int mergedP = start;
    while (leftP < leftSize && rightP < rightSize)
    {
        if (left[leftP] < right[rightP])
            arr[mergedP++] = left[leftP++];
        else
            arr[mergedP++] = right[rightP++];
    }

    while (leftP < leftSize)
        arr[mergedP++] = left[leftP++];
    while (rightP < rightSize)
        arr[mergedP++] = right[rightP++];

    delete[] left;
    delete[] right;
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {1, 7, 2, 9, 10, 0, 50, -10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    mergeSort(arr, 0, n - 1);
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