#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> &arr);

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    vector<int> arr = {1, 7, 2, 9, 10, 0, 50, -10, 5};
    printVec(arr);
    bubbleSort(arr);
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