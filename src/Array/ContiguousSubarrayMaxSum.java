// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// Kadane's Algrithm : https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

package Array;

// Given an array Arr[] of N integers.
// Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
// Time Complexity - O(n)
// Space Complexity - O(1)

public class ContiguousSubarrayMaxSum {
    public static long maxSubarraySum(int[] arr) {
        long currSum = 0, maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            currSum += arr[i];
            if (currSum > maxSum) {
                maxSum = currSum;
            }
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }

    public static void main(String[] args) {
        System.out.println(maxSubarraySum(new int[]{1, 2, 3, -2, 5})); // 9
        System.out.println(maxSubarraySum(new int[]{-1, -2, -3, -4})); // -1
    }
}
