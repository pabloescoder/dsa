// https://practice.geeksforgeeks.org/problems/minimize-the-heights/0
// Reference Video: https://www.youtube.com/watch?v=29uyA4F9t5I

package Array;

// Given heights of n towers and a value k.
// We need to either increase or decrease the height of every tower by k (only once) where k > 0.
// The task is to minimize the difference between the heights of the longest and the shortest tower
// after modifications and output this difference.
// Time Complexity - O(nlogn)
// Space Complexity - O(logn)

public class MinimizeTheHeights {

    private static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

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

    private static void quicksort(int[] arr, int start, int end) {
        if (start < end) {
            int partitionIndex = partition(arr, start, end);
            quicksort(arr, start, partitionIndex - 1);
            quicksort(arr, partitionIndex + 1, end);
        }
    }

    public static int getMinDiff(int[] arr, int k) {
        quicksort(arr, 0, arr.length - 1);
        int min, max;
        int result = arr[arr.length - 1] - arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] >= k) {
                max = Math.max(arr[i - 1] + k, arr[arr.length - 1] - k);
                min = Math.min(arr[i] - k, arr[0] + k);
                result = Math.min(result, max - min);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(getMinDiff(new int[]{2, 6, 3, 4, 7, 2, 10, 3, 2, 1}, 5));  // 7
    }
}
