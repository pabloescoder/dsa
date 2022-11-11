// https://leetcode.com/problems/next-permutation/
#include <iostream>
#include <vector>

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
// More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
// then the next permutation of that array is the permutation that follows it in the sorted container.
// If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// Solution Algorithm:
// https://leetcode.com/problems/next-permutation/solutions/127524/next-permutation/
// Start traversing the array from the left till you find arr[i] > arr[i-1]
// All the elements to the right of arr[i - 1] are in descending order so,
// no rearrangements in that part can create a larger permutation.
// Now we need to replace the number in arr[i - 1] with the next larger number from the right side of the array which is in desc. order
// Let's say arr[j] is the next larger number after arr[i - 1] on the right side of the array
// Swap both the numbers (arr[i - 1] and arr[j])
// Now arr[i - 1] contains the correct number to get the next permutation
// Reverse the elements to the right of arr[i - 1] which are in descending order to ascending order since we need the smallest possible next permutation
// Time Complexity - O(n)
// Space Complexity - O(1)
using namespace std;
void swap(int *a1, int *a2);
void reverseFromIndex(vector<int> &nums, int start);

void nextPermutation(vector<int> &nums)
{
    int pivotIndex{static_cast<int>(nums.size()) - 2};
    while (pivotIndex >= 0 && nums[pivotIndex + 1] <= nums[pivotIndex])
    {
        pivotIndex--;
    }
    if (pivotIndex >= 0)
    {
        int nextGreaterIndex{static_cast<int>(nums.size()) - 1};
        while (nums[nextGreaterIndex] <= nums[pivotIndex])
        {
            nextGreaterIndex--;
        }

        swap(&nums[pivotIndex], &nums[nextGreaterIndex]);
    }
    reverseFromIndex(nums, pivotIndex + 1);
}

int main()
{
    vector<int> v{1, 5, 8, 4, 7, 6, 5, 3, 1};
    nextPermutation(v); // 1 5 8 5 1 3 4 6 7
    for (int i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

void swap(int *a1, int *a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void reverseFromIndex(vector<int> &nums, int start)
{
    int end = nums.size() - 1;
    while (start < end)
    {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}