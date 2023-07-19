// https://leetcode.com/problems/majority-element/description/

class Solution
{
public:
    // Boyer-Moore Majority Vote Algorithm
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int majElem = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                majElem = nums[i];
                count = 1;
            }
            else if (majElem == nums[i])
                count++;
            else
                count--;
        }
        return majElem;
    }

    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> um;
    //     for (int elem : nums)
    //     {
    //         if (um.find(elem) == um.end())
    //             um[elem] = 1;
    //         else
    //             um[elem]++;
    //     }

    //     int maxCount = 0;
    //     int maxElem = 0;
    //     for (auto p : um)
    //     {
    //         if (p.second > maxCount)
    //         {
    //             maxElem = p.first;
    //             maxCount = p.second;
    //         }
    //     }
    //     return maxElem;
    // }
};