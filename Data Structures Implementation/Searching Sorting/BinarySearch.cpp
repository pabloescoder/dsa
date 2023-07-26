#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int> &arr);

bool binarySearch(vector<int> &arr, int elem)
{
    int n = arr.size();
    int start = 0;
    int end = arr.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (elem > arr[mid])
            start = mid + 1;
        else if (elem < arr[mid])
            end = mid - 1;
        else
            return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {-10, 0, 1, 2, 5, 7, 9, 10, 50};
    printVec(arr);
    cout << boolalpha;
    int elem = -10;
    cout << elem << ": " << binarySearch(arr, elem) << endl;
    elem = 25;
    cout << elem << ": " << binarySearch(arr, elem);
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