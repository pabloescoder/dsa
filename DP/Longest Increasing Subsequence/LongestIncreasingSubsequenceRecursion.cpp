#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n)
int lis(const vector<int> &arr, int i, int prev = INT_MIN)
{
    if (i == arr.size())
        return 0;
    if (arr[i] > prev)
        return max(1 + lis(arr, i + 1, arr[i]), lis(arr, i + 1, prev));
    else
        return lis(arr, i + 1, prev);
}

// Time Complexity: O(2^n)
// Space Complexity: O(n)
// Even though both the approaches have the same time complexity, we will go with this approach
// Because it has only one changing parameter so less subproblems to solve
// https://www.udemy.com/course/dynamic-programming-x/learn/lecture/28761010 <--- To understand the approach
int lisSecondApproachMain(const vector<int> &arr, int i)
{
    int maxL = 0;
    for (int j = i + 1; j < arr.size(); j++)
    {
        if (arr[i] < arr[j])
            maxL = max(lisSecondApproachMain(arr, j), maxL);
    }
    return maxL + 1;
}
int lisSecondApproachCaller(const vector<int> &arr)
{
    int maxL = 0;
    for (int i = 0; i < arr.size(); i++)
        maxL = max(lisSecondApproachMain(arr, i), maxL);
    return maxL;
}

int main()
{
    vector<int> arr = {7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7};
    cout << lis(arr, 0) << '\n';
    cout << lisSecondApproachCaller(arr) << '\n';
    vector<int> arr2 = {8, 5, 5, 3};
    cout << lis(arr2, 0) << '\n';
    cout << lisSecondApproachCaller(arr2);
}