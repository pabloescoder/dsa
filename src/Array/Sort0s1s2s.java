// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

package Array;

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// Time Complexity: O(n)
// Space Complexity: O(1)

import java.util.Arrays;

public class Sort0s1s2s {

    private static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    public static void sort012(int[] arr) {
        int zeroPointer = 0;
        int currentPointer = 0;
        int twoPointer = arr.length - 1;
        while (currentPointer <= twoPointer) {
            if (arr[currentPointer] == 0) {
                swap(arr, zeroPointer, currentPointer);
                zeroPointer++;
                currentPointer++;
            } else if (arr[currentPointer] == 2) {
                swap(arr, twoPointer, currentPointer);
                twoPointer--;
            } else if (arr[currentPointer] == 1) {
                currentPointer++;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 1, 0, 2, 1, 0, 2, 2, 1, 0};
        sort012(arr1);
        System.out.println(Arrays.toString(arr1));
    }
}
