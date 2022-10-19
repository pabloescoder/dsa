// https://practice.geeksforgeeks.org/problems/minimize-the-heights/0
// Reference Video: https://www.youtube.com/watch?v=29uyA4F9t5I

package Java.Array;

// Given heights of n towers and a value k.
// We need to either increase or decrease the height of every tower by k (only once) where k > 0.
// The task is to minimize the difference between the heights of the longest and the shortest tower
// after modifications and output this difference.
// Time Complexity - O(nlogn)
// Space Complexity - O(logn)

// Approach (Code at line 63 onwards)
// Sort the array
// Assume that there is a point (a point is BETWEEN 2 elements in the array),
// On the left of the point, add k to all the elements.
// On the right of the point, subtract k from all the elements.
// Check for each possible point in the array.

// Approach - Additional Details
// Our array has 2 segments after following the above approach,
// (A[0]+k, A[1]+k, ..., A[i]+k, A[i+1]-k, A[i+2]-k, ..., A[n]-k)      (n = Java.Array length)
// The first segment (in which we added k) is to the left of our point, A[i]+k is the last element of the first segment
// The second segment (in which we subtracted k) is to the right of the point, A[i+1]-k is the first element of the second segment

// For the first segment, the smallest element is left (left = A[0]+k) and the largest is A[i]+k
// For the second segment, the smallest element is A[i+1] - k, the largest is right (right = A[n]-k)
// So, for each point, the largest element should be either A[i]+k OR right
// Similarly, the smallest element should be either A[i+1]-k OR left

public class MinimizeTheHeights {

    // Helper method for quicksort
    private static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    // Partition method of quicksort
    private static int partition(int[] arr, int start, int end) {
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i += 1;
                swap(arr, j, i);
            }
        }
        swap(arr, i + 1, end);
        return i + 1;
    }

    // Quicksort
    private static void quicksort(int[] arr, int start, int end) {
        if (start < end) {
            int partitionIndex = partition(arr, start, end);
            quicksort(arr, start, partitionIndex - 1);
            quicksort(arr, partitionIndex + 1, end);
        }
    }

    // Main logic
    public static int getMinDiff(int[] arr, int k) {
        quicksort(arr, 0, arr.length - 1);
        int min, max;
        int result = arr[arr.length - 1] - arr[0];
        int right = arr[arr.length - 1] - k;
        int left = arr[0] + k;
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i + 1] >= k) {
                max = Math.max(arr[i] + k, right);
                min = Math.min(arr[i + 1] - k, left);
                result = Math.min(result, max - min);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(getMinDiff(new int[]{2, 6, 3, 4, 7, 2, 10, 3, 2, 1}, 5));  // 7
    }
}
