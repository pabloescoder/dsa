#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O((sum(n) * n)
// Space Complexity: O((sum(n) * n)
bool partition(const vector<int> &arr, int i, int selectSum, int total, vector<vector<int>> &lookup)
{
    int unselectSum = total - selectSum;
    if (selectSum == unselectSum)
        return true;
    if (selectSum > unselectSum || i == arr.size())
        return false;
    if (lookup[i][selectSum] != -1)
        return lookup[i][selectSum];

    lookup[i][selectSum] = partition(arr, i + 1, selectSum + arr[i], total, lookup) ||
                           partition(arr, i + 1, selectSum, total, lookup);
    return lookup[i][selectSum];
}

int main()
{
    cout << boolalpha;
    vector<int> arr = {4, 5, 3, 2, 5, 1};
    int total = 0;
    for (int elem : arr)
        total += elem;
    vector<vector<int>> lookup(arr.size() + 1, vector<int>(total + 1, -1));
    cout << partition(arr, 0, 0, total, lookup) << '\n';

    arr = {5, 6, 2, 3, 8, 1};
    total = 0;
    for (int elem : arr)
        total += elem;
    lookup = vector<vector<int>>(arr.size() + 1, vector<int>(total + 1, -1));
    cout << partition(arr, 0, 0, total, lookup);
}