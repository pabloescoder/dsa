#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVec(vector<int> &arr);

bool linearSearch(vector<int> &arr, int elem)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elem)
            return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 7, 2, 9, 10, 0, 50, -10, 5};
    printVec(arr);
    cout << boolalpha;
    int elem = -10;
    cout << elem << ": " << linearSearch(arr, elem) << endl;
    elem = 25;
    cout << elem << ": " << linearSearch(arr, elem);
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