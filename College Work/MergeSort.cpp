#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

void printArr(vector<int> &arr);
void callMergeSortAndPrintDuration(vector<int> &arr);

void merge(vector<int> &arr, int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    vector<int> left(leftSize);
    vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++)
        left[i] = arr[start + i];
    for (int i = 0; i < rightSize; i++)
        right[i] = arr[mid + i + 1];

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
    {
        arr[mergedP++] = left[leftP++];
    }
    while (rightP < rightSize)
    {
        arr[mergedP++] = right[rightP++];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
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
    vector<int> arr = {636, -111, 275, 551, 465, -307, 415, -561, 386, 699, -136, -185, -651, -295, 500, -498, 243, -383, 816, 431};
    callMergeSortAndPrintDuration(arr);
}

void printArr(vector<int> &arr)
{
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

void callMergeSortAndPrintDuration(vector<int> &arr)
{
    int n = arr.size();
    printArr(arr);
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    printArr(arr);
    cout << "Time: " << duration.count() << " ns" << endl;
}
