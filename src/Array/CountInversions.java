// https://practice.geeksforgeeks.org/problems/inversion-of-array/0

package Array;

// Given an array of integers. Find the Inversion Count in the array.
//
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
// If array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

import java.util.Arrays;

public class CountInversions {

    // Approach 1 - Nested loops
    // Check if array is sorted in descending order, if yes return invCount = factorial(arr.length - 1) (Optimization Step)
    // If array is not in descending order use 2 for loops
    // Outer loop will traverse from index 0 to index arr.length - 2 (Counter variable : i)
    // Inner loop will traverse from index i+1 to index arr.length - 1 (Counter variable : j)
    // If arr[i] > arr[j], increment inversionCount by 1
    // Return inversion count
    // Time Complexity - O(n^2)
    // Space Complexity - O(1)
    // Note: Not accepting due to TLE
    public static long inversionCountUsingNestedLoops(long[] arr) {
        if (arr.length == 1) {
            return 0;
        }

        // Check if array is sorted in desc order, if yes, return inversionCount = factorial(arr.length - 1)
        int descendingOrderStartIndex = 0;
        for (int i = arr.length - 1; i > 0; i--) {
            if (arr[i] > arr[i - 1]) {
                descendingOrderStartIndex = i;
                break;
            }
        }
        if (descendingOrderStartIndex == 0) {
            long invCount = 1;
            for (int i = 2; i < arr.length; i++) {
                invCount *= i;
            }
            return invCount;
        }

        long invCount = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    invCount += 1;
                }
            }
        }
        return invCount;
    }

    // Approach 2 - Modified Merge Sort
    // 1) The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step
    //    until the base case is reached.
    // 2) Create a function merge that counts the number of inversions when two halves of the array are merged,
    // 3) Create two indices i and j, i is the index for the first half, and j is the index of the second half.
    //      3.1) If a[i] is greater than a[j], then there are (mid – i) inversions. As left and right subarrays are sorted,
    //           all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
    // 4) Create a recursive function to divide the array into halves and find the answer by
    //    summing the number of inversions in the first half, the second half and in the merge step.
    // 5) The base case of recursion is when there is only one element in the given half.
    // Time Complexity - O(nlogn)
    // Space Complexity - O(n)
    private static long mergeAndCount(long[] arr, int start, int end, int mid) {
        long[] leftArr = Arrays.copyOfRange(arr, start, mid + 1);
        long[] rightArr = Arrays.copyOfRange(arr, mid + 1, end + 1);
        int i = 0, j = 0, k = start;
        long inversionCount = 0;
        while (i < leftArr.length && j < rightArr.length) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                inversionCount += (mid + 1) - (start + i);
            }
        }

        while (i < leftArr.length)
            arr[k++] = leftArr[i++];
        while (j < rightArr.length)
            arr[k++] = rightArr[j++];

        return inversionCount;
    }

    public static long inversionCountUsingModifiedMergeSort(long[] arr, int start, int end) {
        long count = 0;

        if (start < end) {
            int mid = (start + end) / 2;
            count += inversionCountUsingModifiedMergeSort(arr, start, mid);
            count += inversionCountUsingModifiedMergeSort(arr, mid + 1, end);
            count += mergeAndCount(arr, start, end, mid);
        }

        return count;
    }

    // Helper
    public static long inversionCountUsingModifiedMergeSort(long[] arr) {
        return inversionCountUsingModifiedMergeSort(arr, 0, arr.length - 1);
    }

    public static void main(String[] args) {
        long[] arr = {1, 20, 6, 4, 5};
        System.out.println(inversionCountUsingNestedLoops(arr));  // 5
        System.out.println(inversionCountUsingModifiedMergeSort(arr));  // 5
    }
}
