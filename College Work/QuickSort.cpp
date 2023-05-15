#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

void printArr(vector<int> &arr);
void callQuickSortAndPrintDuration(vector<int> &arr);

int partition(vector<int> &arr, int start, int end)
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

void quickSort(vector<int> &arr, int start, int end)
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
    vector<int> arr = {636, -111, 275, 551, 465, -307, 415, -561, 386, 699, -136, -185, -651, -295, 500, -498, 243, -383, 816, 431};
    callQuickSortAndPrintDuration(arr);
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

void callQuickSortAndPrintDuration(vector<int> &arr)
{
    int n = arr.size();
    printArr(arr);
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    printArr(arr);
    cout << "Array Size: " << n << endl;
    cout << "Time: " << duration.count() << " ns" << endl;
}
