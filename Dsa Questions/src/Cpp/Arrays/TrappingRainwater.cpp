// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
// References:-
// https://www.youtube.com/watch?v=ZI2z5pq0TqA
// https://www.geeksforgeeks.org/trapping-rain-water/
#include <iostream>
#include <algorithm>

// Given an array arr[] of N non-negative integers representing the height of blocks.
// If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.
// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10
// Explanation Image: https://cutt.ly/9M0a5Nj
using namespace std;

// Approach 1 - Precalculation
// 1. Create two arrays left[] and right[] of size N. Create a variable (say max) to store the maximum found till a certain index during traversal.
// 2. Run one loop from start to end:
//      2.1. In each iteration update max and also assign left[i] = max.
// 3. Run another loop from end to start:
//      3.1. In each iteration update max found till now and also assign right[i] = max.
// 4. Traverse the array from start to end.
//      4.1. The amount of water that will be stored in this column is min(left[i], right[i]) – array[i]
//      4.2. Add this value to the total amount of water stored
// 5. Print the total amount of water stored.
// Time Complexity: O(N)
// Space Complexity: O(N)
long long trappedWaterUsingPrecalculation(int arr[], int n)
{
    int *maxLeft = new int[n];
    int *maxRight = new int[n];

    maxLeft[0] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        maxLeft[i] = max(maxLeft[i - 1], arr[i - 1]);
    }

    maxRight[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        maxRight[i] = max(maxRight[i + 1], arr[i + 1]);
    }

    long long trappedWater{0};
    for (int i = 0; i < n; i++)
    {
        int currTrappedWater = min(maxLeft[i], maxRight[i]) - arr[i];
        // If difference is -ve, then trapped water at current index is 0
        if (currTrappedWater > 0)
            trappedWater += currTrappedWater;
    }

    delete[] maxLeft;
    delete[] maxRight;
    return trappedWater;
}

// Approach 2 - Two Pointer (More Optimised) - See video for detailed explanation
// Main Idea:-
// 1. Say we have indices i, j and a boundary of (left, right). where i is the left pointer and j is the right pointer.
// 2. If the minimum is arr[left], we can say that i is bounded in one side by left and no matter whatever the values are in between (i, right),
//    the rightmost boundary of i will at least have height arr[right] which is the probable outermost boundary for i.
// 3. So the water height of water column at index i is arr[left] – arr[i] and we can increment i then.
// 4. Similar things happen for j also.
// Algorithm:-
// 1. Take two pointers leftP and rightP. Initialize leftP to the starting index 0 and rightP to the last index N-1.
// 2. maxLeft will store the max so far. Since leftP is at 0, maxLeft will be arr[0] initially, similarly maxRight = arr[N - 1];
// 3. While leftP < rightP, iterate the array. We have two possible conditions
// 4.1 Condition1 : left_max <= right max
//      Consider Element at index leftP
//      Since we have traversed all elements to the left of leftP, left_max is known
//      For the right max of leftP, We can say that the right max would  always be >= current r_max here
//      So, min(left_max,right_max) would always equal to left_max in this case
//      Increment leftP.
// 4.2 Condition2 : left_max > right max
//      Consider Element at index rightP
//      Since we have traversed all elements to the right of rightP, right_max is known
//      For the left max of rightP, We can say that the left max would  always be >= current l_max here
//      So, min(left_max,right_max) would always equal to right_max in this case
//      Decrement rightP.
// Time Complexity: O(N)
// Space Complexity: O(1)
long long trappedWaterUsingTwoPointer(int arr[], int n)
{
    int leftP{0};
    int rightP{n - 1};
    int maxLeft{arr[leftP]};
    int maxRight{arr[rightP]};
    long long trappedWater{0};

    while (leftP < rightP)
    {
        if (maxLeft <= maxRight)
        {
            leftP++;
            trappedWater += max(0, maxLeft - arr[leftP]);
            maxLeft = max(maxLeft, arr[leftP]);
        }
        else
        {
            rightP--;
            trappedWater += max(0, maxRight - arr[rightP]);
            maxRight = max(maxRight, arr[rightP]);
        }
    }
    return trappedWater;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << trappedWaterUsingPrecalculation(arr, N) << '\n'; // 6
    cout << trappedWaterUsingTwoPointer(arr, N) << '\n';     // 6
    return 0;
}