// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0

package Java.Array;

// Given an array, rotate the array by one position in clock-wise direction.
// Time Complexity - O(n)
// Space Complexity - O(1)

import java.util.Arrays;

public class RotateBy1 {
    public static void rotate(int[] arr) {
        int temp = arr[arr.length - 1];
        for (int i = arr.length - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {9, 8, 7, 6, 5, 4, 3, 10};
        rotate(arr);
        System.out.println(Arrays.toString(arr)); // [10, 9, 8, 7, 6, 5, 4, 3]
    }
}
