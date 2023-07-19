// https://leetcode.com/problems/merge-sorted-array/description/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> nums1Temp(nums1.begin(), nums1.begin() + m);
        while (i < m && j < n)
        {
            if (nums1Temp[i] < nums2[j])
                nums1[k++] = nums1Temp[i++];
            else
                nums1[k++] = nums2[j++];
        }

        while (i < m)
            nums1[k++] = nums1Temp[i++];
        while (j < n)
            nums1[k++] = nums2[j++];
    }
};