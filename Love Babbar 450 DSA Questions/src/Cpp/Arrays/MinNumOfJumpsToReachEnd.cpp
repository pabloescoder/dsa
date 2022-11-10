// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

#include <iostream>
#include <algorithm> // for max()

// Given an array of N integers arr[] where each element represents the max length of the jump that can be made forward from that element.
// Find the minimum number of jumps to reach the end of the array (starting from the first element).
// If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.
// Time Complexity - O(n)
// Space Complexity - O(1)

// Approach - Greedy
// Keep moving forward as long as it is possible to, once we no longer have any more moves left,
// Jump from the element which gets us the furthest distance possible compared to all the other elements which we've traversed.
// There are 2 things which we keep track of in this approach
//      1. Maximum Reach: It is the furthest index which we can possibly go to using one of the jumps
//      2. Moves: It tracks the number of moves which can be made using the last jump which we did
// Initially we set maximumReach AND remainingMoves to arr[0]. Since we have to make the first jump at index 0.
// Since the first jump is compulsory, jumps is initialised to 1.
// Then iterate over the array, starting from index 0, and update the maximumPosition we can reach accordingly,
// as well as decrease the moves which we can make by 1 in every iteration
// If no more moves are left (moves = 0), then jump from the element which allows us to reach us the maximum distance
// and increment the number of jumps by 1.

using namespace std;

int minJumps(int arr[], int n)
{
    if (n == 1)
    {
        return 0; // We are already at the end
    }

    int maximumReach{arr[0]};
    int remainingMoves{arr[0]};
    int jumps = 1; // Because we have to take the starting jump
    for (int i = 1; i < n - 1; i++)
    {
        maximumReach = max(maximumReach, arr[i] + i);
        remainingMoves -= 1;

        if (remainingMoves == 0)
        {
            jumps += 1;
            remainingMoves = maximumReach - i;
        }
        // If remainingMoves is negative, we can't reach the end
        else if (remainingMoves < 0)
        {
            return -1;
        }
    }

    if (maximumReach < n - 1)
    {
        return -1;
    }
    return jumps;
}

int main()
{
    int arr[]{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, n); // 3
    return 0;
}