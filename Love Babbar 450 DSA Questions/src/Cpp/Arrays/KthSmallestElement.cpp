// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <iostream>
using namespace std;

void swap(int arr[], int first, int second);
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

int kthSmallestUsingQuicksort(int arr[], int size, int k)
{
    quickSort(arr, 0, size - 1);
    return arr[k - 1];
}

int main()
{
    int arr1[]{7, 4, 10, 20, 15};
    int size{sizeof(arr1) / sizeof(arr1[0])};
    cout << kthSmallestUsingQuicksort(arr1, size, 4); // 15
}

void swap(int arr[], int first, int second)
{
    int temp{arr[first]};
    arr[first] = arr[second];
    arr[second] = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot{arr[end]};
    int i{start - 1};

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
        swap(arr, i + 1, end);
    }
    return i + 1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}