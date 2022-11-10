// https://leetcode.com/problems/find-the-duplicate-number/

// Reference (For Floyd cycle detection algo)
// https://www.youtube.com/watch?v=PvrxZaH_eZ4

#include <iostream>
#include <vector>
#include <cstdlib> // For abs()

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

using namespace std;

// Approach 1 - Negative Marking (Modifies array, however we can restore the array back to the original one)
// Since the array has numbers in the range 1 to n only, and the size of the array is n + 1 we can use that to our benefit.
// For every number arr[i], set the value of mod(arr[i]) to -arr[i]
// If after setting mod(arr[i]) to -arr[i], the element arr[i] is positive, then the duplicate number is arr[i]
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: Even though this approach modifies the array, we can make all the digits positive and restore the original array.
int findDuplicateUsingNegativeMarking(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);
        if (nums[index] < 0)
        {
            return index;
        }
        nums[index] *= -1;
    }
    return -1;
}

// Approach 2 - Floyd's tortoise and hare algo (cycle detection)
// Time Complexity : O(N)
// Space Complexity: O(1)
// Array is not modified
// Visualise a Linked List with each element arr[i] pointing to the node with index i
// Since one number is duplicate, 2 elements will point to the same node
// So we will have a cycle in the LL. That's why we can use Floyd's tortoise and hare algo to detect that cycle
// Take 2 pointers slow and fast initialise them to 0.
// while (true)
//   move slow by 1 and move fast by 2 ( slow = arr[slow] and fast = arr[arr[fast]])
// Once they meet, break the loop, set slow to 0, and increment both slow and fast by one this time
// Return the index of the point where they meet again. This is where the cycle starts.

int findDuplicateUsingTortoiseAndHare(vector<int> &nums)
{
    int slow{0};
    int fast{0};
    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
        {
            break;
        }
    }
    slow = 0;

    // Move both by 1
    while (true)
    {
        if (slow == fast)
        {
            return slow;
        }
        slow = nums[slow];
        fast = nums[fast];
    }
}

int main()
{
    vector<int> v1{3, 1, 3, 4, 2};
    vector<int> v2{3, 1, 3, 4, 2};
    cout << findDuplicateUsingNegativeMarking(v1) << '\n'; // 3
    cout << findDuplicateUsingTortoiseAndHare(v2) << '\n'; // 3
    return 0;
}