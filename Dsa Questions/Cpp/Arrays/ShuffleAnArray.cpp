// https://leetcode.com/problems/shuffle-an-array/description/

#include <iostream>
#include <cstdlib> // srand and rand
#include <ctime>   // time
#include <vector>

// Given an integer array nums, design an algorithm to randomly shuffle the array.
// All permutations of the array should be equally likely as a result of the shuffling.

// Implement the Solution class:
// Solution(int[] nums) Initializes the object with the integer array nums.
// int[] reset() Resets the array to its original configuration and returns it.
// int[] shuffle() Returns a random shuffling of the array.

// Time Complexity: O(N)
// Space Complexity: O(N)

using namespace std;
class Solution
{
    vector<int> nums;

public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
        srand(time(0));
    }

    vector<int> reset()
    {
        return nums;
    }

    // Fisher-Yates Algorithm
    vector<int> shuffle()
    {
        vector<int> shuffled = nums;
        for (int i = 0; i < shuffled.size(); i++)
        {
            int randIdx = (rand() % (shuffled.size() - i)) + i;
            swap(shuffled[i], shuffled[randIdx]);
        }
        return shuffled;
    }
};