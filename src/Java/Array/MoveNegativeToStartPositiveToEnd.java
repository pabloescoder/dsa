// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
// Reference articles :-
// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/

package Java.Array;

// An array contains both positive and negative numbers in random order.
// Rearrange the array elements so that all negative numbers appear before all positive numbers.
// Note: Order of elements is not important here.

import java.util.Arrays;

public class MoveNegativeToStartPositiveToEnd {

    // Approach 1 - Two Pointer approach
    // Order of negative & positive numbers corresponding to input array is NOT maintained
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    private static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    public static void move(int[] arr) {
        int negativePointer = 0;
        int positivePointer = arr.length - 1;
        while (negativePointer <= positivePointer) {
            if (arr[negativePointer] > 0) {
                swap(arr, negativePointer, positivePointer);
                positivePointer--;
            } else if (arr[negativePointer] < 0) {
                negativePointer++;
            }
        }
    }

    // Approach 2 - Modified Partition Process of QuickSort
    // Order of negative & positive numbers corresponding to input array is maintained
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    // We can reverse the order of positive numbers whenever the relative order is changed.
    // This will happen,
    // If there are more than one positive elements between the last negative number in the left subarray
    // and the current negative element.

    // Current Java.Array :- [Ln, P1, P2, P3, N1, .......]
    // Here, Ln is the left subarray(can be empty) that contains only negative elements.
    // P1, P2, P3 are the positive numbers and N1 is the negative number that we want to move at correct place.
    // If difference of indices between positive number and negative number is greater than 1,
    //        1. Swap P1 and N1, we get [Ln, N1, P2, P3, P1, ......]
    //        2. Rotate array by one position to right, i.e. rotate array [P2, P3, P1], we get [Ln, N1, P1, P2, P3, ...]

    // Rotates the subarray specified by start and end (inclusive) to the right by one
    private static void rotateSubArrayRightBy1(int[] arr, int start, int end) {
        int temp = arr[end];
        for (int j = end; j > start; j--) {
            arr[j] = arr[j - 1];
        }
        arr[start] = temp;
    }

    public static void moveWhileMaintainingOrder(int[] arr) {
        int lastNegativePointer = -1;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) {
                lastNegativePointer++;
                swap(arr, lastNegativePointer, i);

                if (i - lastNegativePointer >= 2) {
                    rotateSubArrayRightBy1(arr, lastNegativePointer + 1, i);
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
        int[] arr2 = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
        System.out.println("Initial Java.Array: " + Arrays.toString(arr) + System.lineSeparator());
        move(arr);
        moveWhileMaintainingOrder(arr2);
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(arr2));
    }
}
