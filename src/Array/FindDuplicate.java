// https://leetcode.com/problems/find-the-duplicate-number/

package Array;

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

import java.util.HashSet;

public class FindDuplicate {

    // Approach 1 - HashSet
    // Traverse the array and add each element to the HashSet using the add() method.
    // add() returns true if the element was not present previously and was added.
    // add() returns false if the element was present previously and hence was not added.
    // If add() returns false, that is our duplicate element.
    // Time Complexity - O(n)
    // Space Complexity - O(n)

    public static int findDuplicateUsingHashSet(int[] nums) {
        HashSet<Integer> hs = new HashSet<>();
        for (int num : nums) {
            if (!hs.add(num)) {
                return num;
            }
        }
        return -1;
    }

    // Approach 2 - Mark visited value within the array
    // Since all the values in the array are between 1 to n, and the array size is n+1
    // For each element at index i, set nums[element] to its negative value, ie. (nums[element] = -nums[element])
    // Whenever you encounter a negative number while accessing nums[element], return element
    // Time Complexity - O(n)
    // Space Complexity - O(1)

    public static int findDuplicateUsingMarking(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int element = Math.abs(nums[i]);  // Prevents ArrayIndexOutOfBoundsException (accessing negative index)
            if (nums[element] < 0) {
                return element;
            }
            nums[element] = -nums[element];
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(findDuplicateUsingHashSet(new int[]{1, 3, 4, 2, 2}));  // 2
        System.out.println(findDuplicateUsingMarking(new int[]{1, 3, 4, 2, 2}));  // 2
    }
}
