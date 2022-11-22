// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include <iostream>
#include <unordered_map>
#include <algorithm> // for max()

// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
// Similar Logic to SubarrayWith0Sum.cpp
// However here length matters and we need the largest subarray length.
using namespace std;

int maxLen(vector<int> &A, int n)
{
    unordered_map<int, int> sumTillIndex;
    int sumTillNow{0};
    int maxL{0};
    for (int i = 0; i < n; i++)
    {
        sumTillNow += A[i];

        // If prefix sum is 0, then it means that subarray with 0 sum is from index 0 to i
        if (sumTillNow == 0)
        {
            maxL = max(maxL, i + 1);
            continue;
        }

        if (sumTillIndex.find(sumTillNow) != sumTillIndex.end())
        {
            maxL = max(maxL, i - sumTillIndex[sumTillNow]);
        }
        else
        {
            sumTillIndex[sumTillNow] = i;
        }
    }
    return maxL;
}

int main()
{
    vector<int> v{15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(v, v.size()); // 5
    return 0;
}