// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
#include <iostream>
#include <unordered_map>

// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
// arr[] = {1, 5, 7, 1}
// Output: 2
// Explanation:
// arr[0] + arr[1] = 1 + 5 = 6
// and arr[1] + arr[3] = 5 + 1 = 6
// Time Complexity: O(N)
// Space Complexity: O(N)

using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> numFreq;
    int reqNumber{0};
    int pairsCount{0};
    for (int i = 0; i < n; i++)
    {
        reqNumber = k - arr[i];
        if (numFreq.find(reqNumber) != numFreq.end())
        {
            pairsCount += numFreq[reqNumber];
        }
        numFreq[arr[i]] += 1;
    }
    return pairsCount;
}

int main()
{
    int arr[]{1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << getPairsCount(arr, n, k); // 2
    return 0;
}