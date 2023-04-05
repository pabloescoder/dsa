#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
int lisMain(const vector<int> &arr, int i, vector<int> &lookup)
{
    if (lookup[i] != -1)
        return lookup[i];

    int maxL = 0;
    for (int j = i + 1; j < arr.size(); j++)
    {
        if (arr[i] < arr[j])
            maxL = max(lisMain(arr, j, lookup), maxL);
    }
    lookup[i] = maxL + 1;
    return lookup[i];
}
int lisCaller(const vector<int> &arr)
{
    vector<int> lookup(arr.size() + 1, -1);
    int maxL = 0;
    for (int i = 0; i < arr.size(); i++)
        maxL = max(lisMain(arr, i, lookup), maxL);
    return maxL;
}

int main()
{
    vector<int> arr = {7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7};
    cout << lisCaller(arr) << '\n';
    vector<int> arr2 = {8, 5, 5, 3};
    cout << lisCaller(arr2);
}