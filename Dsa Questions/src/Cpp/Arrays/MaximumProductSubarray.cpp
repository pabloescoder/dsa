// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
#include <iostream>
#include <vector>
#include <algorithm>

// Given an array Arr[] that contains N integers (may be positive, negative or zero).
// Find the product of the maximum product subarray.
// Approach - Modified Kadane's algorithm
// Use 2 variables maxTillNow and minTillNow to keep track of max and min product so far
// Whenever current element is negative, swap maxTillNow and minTillNow
// Remaining is same as Kadane's algo, just instead of sum we are taking the product this time.
// Time Complexity: O(N)
// Space Complexity: O(1)
using namespace std;
void swap(long long *a1, long long *a2);

long long maxProduct(vector<int> arr, int n)
{
    long long maxTillNow{arr[0]};
    long long minTillNow{arr[0]};
    long long maxProd{arr[0]};
    for (int i = 1; i < arr.size(); i++)
    {
        // If current element is negative, then maxTillNow and minTillNow will be swapped
        // Because we are multiplying by -ve so sign will change.
        if (arr[i] < 0)
        {
            swap(&maxTillNow, &minTillNow);
        }
        // Kadane's algo (modified)
        maxTillNow = max(static_cast<long long>(arr[i]), maxTillNow * arr[i]);
        minTillNow = min(static_cast<long long>(arr[i]), minTillNow * arr[i]);
        maxProd = max(maxProd, maxTillNow);
    }
    return maxProd;
}

int main()
{
    vector<int> v1{-2, -3, 0, -2, -40};
    cout << maxProduct(v1, v1.size()) << '\n'; // 80
    vector<int> v2{6, -3, -10, 0, 2};
    cout << maxProduct(v2, v2.size()) << '\n'; // 180
}

void swap(long long *a1, long long *a2)
{
    long long temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}