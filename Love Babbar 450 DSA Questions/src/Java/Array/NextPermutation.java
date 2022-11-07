// https://leetcode.com/problems/next-permutation/

package Java.Array;

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
//
// For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1]...
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
// More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
// then the next permutation of that array is the permutation that follows it in the sorted container.
//
// If such arrangement is not possible, the array must be rearranged as the lowest possible order
// (i.e., sorted in ascending order).
//
// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.
//
// The replacement must be in place and use only constant extra memory.

// Solution Algorithm:
// https://leetcode.com/problems/next-permutation/discuss/13994/Readable-code-without-confusing-ij-and-with-explanation
// Start traversing the array from the left till you find arr[i] > arr[i-1]
// All the elements to the right of arr[i - 1] are in descending order so,
// no rearrangements in that part can create a larger permutation.
// Now we need to replace the number in arr[i - 1] with the next larger number from the right side of the array which is in desc. order
// Let's say arr[j] is the next larger number after arr[i - 1] on the right side of the array
// Swap both the numbers (arr[i - 1] and arr[j])
// Now arr[i - 1] contains the correct number to get the next permutation
// Sort the elements to the right of arr[i - 1] which are in descending order to ascending order since we need the smallest possible next permutation
// Time Complexity - O(n)
// Space Complexity - O(1)

import java.util.Arrays;

public class NextPermutation {
    private static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    public static void nextPermutation(int[] nums) {
        int descendingOrderStartIndex = 0;

        for (int i = nums.length - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                descendingOrderStartIndex = i;
                break;
            }
        }

        int pivot = descendingOrderStartIndex - 1;

        if (pivot != -1) {
            for (int i = nums.length - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums, pivot, i);
                    break;
                }
            }
        }

        int i = descendingOrderStartIndex;
        int j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    public static void main(String[] args) {
        int[] arr1 = new int[]{1, 2, 3};
        int[] arr2 = new int[]{3, 2, 1};
        int[] arr3 = new int[]{1, 5, 8, 4, 7, 6, 5, 3, 1};

        nextPermutation(arr1);
        nextPermutation(arr2);
        nextPermutation(arr3);

        System.out.println(Arrays.toString(arr1)); // [1, 3, 2]
        System.out.println(Arrays.toString(arr2)); // [1, 2, 3]
        System.out.println(Arrays.toString(arr3)); // [1, 5, 8, 5, 1, 3, 4, 6, 7]
    }
}
