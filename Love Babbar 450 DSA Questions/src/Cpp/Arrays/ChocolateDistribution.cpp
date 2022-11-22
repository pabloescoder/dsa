// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
#include <iostream>
#include <vector>
#include <algorithm>

// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet.
// Each packet can have a variable number of chocolates.
// There are M students, the task is to distribute chocolate packets among M students such that :
//  1. Each student gets exactly one packet.
//  2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

// Input:
// N = 8, M = 5
// A = {3, 4, 1, 9, 56, 7, 9, 12}
// Output: 6
// Explanation: The minimum difference between
// maximum chocolates and minimum chocolates
// is 9 - 3 = 6 by choosing following M packets :
// {3, 4, 9, 7, 9}.
using namespace std;

// The idea is based on the observation that to minimize the difference, we must choose consecutive elements from a sorted packet.
// We first sort the array arr[0..n-1], then find the subarray of size m with the minimum difference between the last and first elements.
// Time Complexity: O(NlogN)
// Space Complexity: O(logN)
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long start{0};
    long long end{m - 1};

    long long minDiff = a[end] - a[start];
    while (end < n - 1)
    {
        start++;
        end++;
        minDiff = min(minDiff, a[end] - a[start]);
    }
    return minDiff;
}

int main()
{
    vector<long long> packets{12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    long long m{7};
    cout << findMinDiff(packets, packets.size(), m); // 10
}