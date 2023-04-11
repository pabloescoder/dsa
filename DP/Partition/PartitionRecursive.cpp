#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n)
bool partition(const vector<int> &arr, int i, int selectSum, int total)
{
    int unselectSum = total - selectSum;
    if (selectSum == unselectSum)
        return true;
    if (selectSum > unselectSum || i == arr.size())
        return false;

    return (partition(arr, i + 1, selectSum + arr[i], total) ||
            partition(arr, i + 1, selectSum, total));
}

int main()
{
    cout << boolalpha;
    vector<int> arr = {4, 5, 3, 2, 5, 1};
    int total = 0;
    for (int elem : arr)
        total += elem;
    cout << partition(arr, 0, 0, total) << '\n';

    arr = {5, 6, 2, 3, 8, 1};
    total = 0;
    for (int elem : arr)
        total += elem;
    cout << partition(arr, 0, 0, total);
}