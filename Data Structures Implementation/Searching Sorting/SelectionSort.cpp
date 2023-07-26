#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int> &arr);

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int minIdx;
    for (int i = 0; i < n; i++)
    {
        minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[minIdx], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 7, 2, 9, 10, 0, 50, -10, 5};
    printVec(arr);
    selectionSort(arr);
    printVec(arr);
}

void printVec(vector<int> &arr)
{
    int n = arr.size();
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ((i == n - 1) ? " " : ", ");
    }
    cout << "]\n";
}