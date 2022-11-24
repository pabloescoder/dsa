// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0
// Reference: https://www.youtube.com/watch?v=6_-zOrJlTDo
#include <iostream>
#include <algorithm>

// Given an array arr of n positive integers and a number k.
// One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j].
// Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.
using namespace std;

// Approach - Two Pointer + Sliding Window
// 1. Find the count of all elements which are less than or equal to ‘k’. Let’s say the count is ‘fav’ (favorable count)
// 2. Using the two-pointer technique for a window of length ‘fav’,
//    each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘nonFav’.
// 3. Repeat step 2, by sliding the window by one index for every window of length ‘fav’
//    and take a minimum of count ‘nonFav’ among them. This will be the final answer.
// Time Complexity: O(N)
// Space Complexity: O(1)
int minSwap(int arr[], int n, int k)
{
    // Favorable elements are equal to the number of elements <= k
    int fav{0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            fav++;
    }

    // The size of our window will be equal to the no. of favorable elements
    // Because we need all the favorable elements in one contiguous subarray
    // Non favorable elements in the first window will be the no. of elements > k
    // We will keep shifting the window by one index and update the no. of non favorable elements
    // The window with the least no. of non favorable elements will give us the min swaps.
    int nonFav{0};
    for (int i = 0; i < fav; i++)
    {
        if (arr[i] > k)
            nonFav++;
    }

    int start{0}, end{fav - 1};
    int swaps{nonFav};
    while (end < n)
    {
        swaps = min(swaps, nonFav);
        end++;
        if (end < n && arr[end] > k)
            nonFav++;

        if (start < n && arr[start] > k)
            nonFav--;
        start++;
    }
    return swaps;
}

int main()
{
    int arr[]{2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << minSwap(arr, n, k); // 2
}