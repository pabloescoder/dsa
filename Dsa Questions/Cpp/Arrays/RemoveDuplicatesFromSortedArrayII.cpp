// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution
{
public:
    // Can be generalised for k duplicates by replacing 2 with k
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int n : nums)
        {
            if (i < 2 || n > nums[i - 2])
                nums[i++] = n;
        }
        return i;
    }
};