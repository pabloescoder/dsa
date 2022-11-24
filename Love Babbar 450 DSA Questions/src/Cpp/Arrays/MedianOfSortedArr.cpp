// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1
#include <iostream>
#include <vector>
#include <algorithm>

// Given two sorted arrays array1 and array2 of size m and n respectively.
// Find the median of the two sorted arrays.
// Input:
// m = 3, n = 4
// array1[] = {1,5,9}
// array2[] = {2,3,6,7}
// Output: 5
// Explanation: The middle element for
// {1,2,3,5,6,7,9} is 5
using namespace std;

// Approach 1 - Two Pointers - Count while merging (My Code - Modified Merge Method)
// 1. Maintain a track of the current Merged Element using a variable currIdx and storing the element in currElement.
// 2. No need to create an additional array to actually merge the elements because we are just concerned with the index.
// 3.1. If the sum of both arrays is even, then median will be given by average of elements at indices [(totalLen / 2) - 1] and [totalLen / 2]
// 3.2. If the sum of both arrays is odd, then the median will be given by element at index [totalLen / 2]
// More explanation in the function below.
// Time Complexity: O(M + N)
// Space Complexity: O(1)
double findMedianSortedArraysUsingModifiedMerge(vector<int> &nums1, vector<int> &nums2)
{
    int totalLen{static_cast<int>(nums1.size() + nums2.size())};
    bool isEven{totalLen % 2 == 0};
    int currIdx{0};
    double currElement{};     // To store element at current index (needed for calculating the median)
    int nums1P{0}, nums2P{0}; // Pointers for respective subarrays

    // Iterate while both pointers have not reached the end
    while (nums1P < nums1.size() && nums2P < nums2.size())
    {
        // If nums1 has the smaller element, that will go to the merged array first
        if (nums1[nums1P] <= nums2[nums2P])
            currElement = nums1[nums1P++];
        // Else element in nums2 will go to the merged array
        // Note: There is no merged array since we are using a counter to keep track of the index
        else
            currElement = nums2[nums2P++];

        // If the total length (nums1 + nums2) is odd, and current idx is totalLen / 2
        // Then we have found the median element, return it.
        if (!isEven && currIdx == totalLen / 2)
        {
            return currElement;
        }
        // Otherwise if the total length is even, and current index is (totalLen / 2) - 1
        // Then we have the first element of the median pair
        // Note: Since length is even we need average of both (n/2 - 1)th and (n/2)th element
        else if (isEven && currIdx == (totalLen / 2) - 1)
        {
            // If both nums1P and nums2P are less than their respective array lengths,
            // The second element of the pair will be the minimum of the elements in both the arrays
            if (nums1P < nums1.size() && nums2P < nums2.size())
            {
                return (currElement + min(nums1[nums1P], nums2[nums2P])) / 2;
            }
            // If nums1P has reached the end, then the second element will be from nums2
            else if (nums1P >= nums1.size())
            {
                return (currElement + nums2[nums2P]) / 2;
            }
            // Otherwise if nums2P has reached the end, then second element will be from nums1
            else
            {
                return (currElement + nums1[nums1P]) / 2;
            }
        }
        currIdx++;
    }

    // If nums2 has less elements and above while loop terminated,
    // then check nums1P for the median elements
    // Logic for getting the median element is the same as above
    while (nums1P < nums1.size())
    {
        currElement = nums1[nums1P++];
        if (!isEven && currIdx == totalLen / 2)
        {
            return currElement;
        }
        else if (isEven && currIdx == (totalLen / 2) - 1)
        {
            return (currElement + nums1[nums1P]) / 2;
        }
        currIdx++;
    }

    // If nums1 has less elements and the first while loop terminated,
    // then check nums1P for the median elements
    while (nums2P < nums2.size())
    {
        currElement = nums2[nums2P++];
        if (!isEven && currIdx == totalLen / 2)
        {
            return currElement;
        }
        else if (isEven && currIdx == (totalLen / 2) - 1)
        {
            return (currElement + nums2[nums2P]) / 2;
        }
        currIdx++;
    }
    return -1;
}

// Approach 2 - Two Pointers - Count while merging (Shorter Code - Modified Merge)
// Reference: https://www.interviewbit.com/blog/median-of-two-sorted-arrays/
// 1. The first element of both lists is compared.
// 2. If sorted in ascending order, the smaller element among two becomes a new element of the sorted list.
// 3. Don't store this in a sorted list, instead use a variable to keep track of the current Index, median1 (m1) and median2 (m2).
//      3.1. If the sum of both arrays is even, then we will need average of both m1 and m2.
//           m1 = element at index [(totalLen / 2) - 1] AND m2 = element at index [totalLen / 2]
//      3.2. If the sum of both arrays is odd, then we just need m1
//           m2 = element at index [totalLen / 2]
// 4. This procedure is repeated until we reach the elements at indices mentioned above
// Time Complexity: O(M + N)
// Space Complexity: O(1)
double findMedianSortedArraysUsingModifiedMergeShorter(vector<int> &nums1, vector<int> &nums2)
{
    int m = static_cast<int>(nums1.size()); // m = sizeof nums1
    int n = static_cast<int>(nums2.size()); // n = sizeof nums2
    double m1{-1}, m2{-1};
    int nums1P{0}, nums2P{0};
    int currIdx{};

    // Odd length
    if ((m + n) % 2 == 1)
    {
        for (currIdx = 0; currIdx <= (m + n) / 2; currIdx++)
        {
            if (nums1P != m && nums2P != n)
            {
                m1 = (nums1[nums1P] > nums2[nums2P]) ? nums2[nums2P++] : nums1[nums1P++];
            }
            else if (nums1P < m)
            {
                m1 = nums1[nums1P++];
            }
            else
            {
                m1 = nums2[nums2P++];
            }
        }
        return m1;
    }
    // Even Length
    else
    {
        for (currIdx = 0; currIdx <= (m + n) / 2; currIdx++)
        {
            m1 = m2;
            if (nums1P != m && nums2P != n)
            {
                m2 = (nums1[nums1P] > nums2[nums2P]) ? nums2[nums2P++] : nums1[nums1P++];
            }
            else if (nums1P < m)
            {
                m2 = nums1[nums1P++];
            }
            else
            {
                m2 = nums2[nums2P++];
            }
        }
        return (m1 + m2) / 2;
    }
}

// Approach 3 - Binary Search (More Optimised Time Complexity)
// References:
// https://www.youtube.com/watch?v=LPFhl65R7ww (Good video - Clears concepts)
// https://www.interviewbit.com/blog/median-of-two-sorted-arrays/#:~:text=Complexity%3A%20O(1)-,Efficient%20Approach
// See video for explanation
// Time Complexity: O(log(min(M, N)))
// Space Complexity: O(1)
double findMedianSortedArraysUsingBinarySearch(vector<int> &nums1, vector<int> &nums2)
{
    // This function assumes that length of nums1 < length of nums2. If that is not the case call it again with swapped values.
    if (nums1.size() > nums2.size())
        return findMedianSortedArraysUsingBinarySearch(nums2, nums1);

    int start{0};
    int end{static_cast<int>(nums1.size())}; // See below
    // End is taken as the length of the shorter array instead of its last index because of the logic used in this approach
    // According to the approach if partitionX = 4 then the shorter array has 4 elements in the left of the partition
    // Inorder for this logic to work properly, end must be the length of the smaller array M instead of M - 1 (last index)

    while (start <= end)
    {
        int partitionX = (start + end) / 2;
        // partitionX + partitionY = (M + N + 1) / 2   <--- 1 needs to be added so that it works properly with arrays of both odd and even length
        int partitionY = ((nums1.size() + nums2.size() + 1) / 2) - partitionX;

        // If there are no elements to the left of the partition, replace it with INT_MIN
        int maxLeftX = (partitionX - 1 >= 0) ? nums1[partitionX - 1] : INT_MIN;
        int maxLeftY = (partitionY - 1 >= 0) ? nums2[partitionY - 1] : INT_MIN;

        // If there are no elements to the right of the partition, replace it with INT_MAX
        int minRightX = (partitionX < nums1.size()) ? nums1[partitionX] : INT_MAX;
        int minRightY = (partitionY < nums2.size()) ? nums2[partitionY] : INT_MAX;
        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if ((nums1.size() + nums2.size()) % 2 == 0) // Even length
            {
                // First median element will be max element to the left of partition in both arrays
                // and second median element will be min element to the right of partition in both arrays
                return static_cast<double>(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            }
            else
            {
                // If array is of odd length. Median is given by max element to the left of the partition
                return (max(maxLeftX, maxLeftY));
            }
        }
        // If element in the smaller array to the left of partitionX is greater than element in the larger array to the right of partitionY
        else if (maxLeftX > minRightY)
        {
            // Then we are too far right in the smaller array, change end to partitionX - 1 (Binary Search in left subarray)
            end = partitionX - 1;
        }
        else
        {
            // Else we are too far left in the smaller array, change start to partitionX + 1 (Binary Search in the right subarray)
            start = partitionX + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1_1{1, 2};
    vector<int> arr1_2{3, 4};
    vector<int> arr2_1{2, 3, 6, 7};
    vector<int> arr2_2{1, 5, 9};
    cout << findMedianSortedArraysUsingModifiedMerge(arr1_1, arr1_2) << '\n';        // 2.5
    cout << findMedianSortedArraysUsingModifiedMerge(arr2_1, arr2_2) << '\n';        // 5
    cout << findMedianSortedArraysUsingModifiedMergeShorter(arr1_1, arr1_2) << '\n'; // 2.5
    cout << findMedianSortedArraysUsingModifiedMergeShorter(arr2_1, arr2_2) << '\n'; // 5
    cout << findMedianSortedArraysUsingBinarySearch(arr1_1, arr1_2) << '\n';         // 2.5
    cout << findMedianSortedArraysUsingBinarySearch(arr2_1, arr2_2) << '\n';         // 5
}