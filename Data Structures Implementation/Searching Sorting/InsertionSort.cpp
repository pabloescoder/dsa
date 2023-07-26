#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int> &arr);

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {1, 7, 2, 9, 10, 0, 50, -10, 5};
    printVec(arr);
    insertionSort(arr);
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