// Time Complexity O(n)
// Space Complexity O(1)

package Java.Array;

import java.util.Arrays;

public class ReverseTheArray {
    public static void reverseArr(int[] arr) {
        for (int start = 0, end = arr.length - 1; start < arr.length / 2; start++, end--) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4, 5, 6};
        int[] arr2 = {5, 4, 3, 2, 1};
        reverseArr(arr1);
        reverseArr(arr2);
        System.out.println(Arrays.toString(arr1));
        System.out.println(Arrays.toString(arr2));
    }
}
