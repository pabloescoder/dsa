// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0

package Array;

// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order without using any extra space.
// Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Approach
// Consider three pointers i = 0, j = 0 and k = arr1.length - 1
// While i <= k AND j <= arr2.length - 1
//     If arr1[i] < arr2[j]
//          Then increment i
//     Else
//          Swap arr1[k] and arr2[j]
//          Increment j
//          Decrement k
// Sort arr1 as well as arr2
// Time Complexity - O((n+m)log(n+m)) (n, m are the lengths of arr1 and arr2 respectively)
// Space Complexity - O(1)

import java.util.Arrays;

public class MergeSortedWithoutExtraSpace {
    private static void merge(long[] arr1, long[] arr2) {
        int i = 0, j = 0;
        int k = arr1.length - 1;
        while (i <= k && j <= arr2.length - 1) {
            if (arr1[i] < arr2[j]) {
                i += 1;
            } else {
                long temp = arr2[j];
                arr2[j] = arr1[k];
                arr1[k] = temp;
                j += 1;
                k -= 1;
            }
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
    }

    public static void main(String[] args) {
        long[] arr1 = {1, 3, 5, 7};
        long[] arr2 = {0, 2, 6, 8, 9};
        System.out.println("Before:- \n" + Arrays.toString(arr1) + "\n" + Arrays.toString(arr2));
        merge(arr1, arr2);
        System.out.println("\nAfter:- \n" + Arrays.toString(arr1) + "\n" + Arrays.toString(arr2));

        /*
        Output:-
        Before:-
        [1, 3, 5, 7]
        [0, 2, 6, 8, 9]

        After:-
        [0, 1, 2, 3]
        [5, 6, 7, 8, 9]
        */
    }
}
