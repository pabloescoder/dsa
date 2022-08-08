// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Reference videos & articles :-
// https://www.youtube.com/watch?v=t0Cq6tVNRBA
// https://www.youtube.com/watch?v=VkKmmwzfIG4
// https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

// Given an array arr[] and an integer K where K is smaller than size of array,
// the task is to find the Kth smallest element in the given array.
// It is given that all array elements are distinct.

// Increasing order of time complexities = O(Approach 4) < O(Approach 2) < O(Approach 3) < O(Approach 1)

package Array;

import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class KthSmallestElement {

    // Approach 1 - Sort the array (quicksort) then return element at (K - 1)th index
    // Time complexity - O(nlogn)
    // Space complexity - O(logn) - Because of recursive calls - Assuming average case

    // Helper method for swapping 2 elements of an array
    private static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    // Helper method for returning partition index after performing partition function in quicksort
    private static int partition(int[] arr, int start, int end) {
        int pivot = arr[end];
        int i = start - 1;

        for (int j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, end);
        return i + 1;
    }

    // Quicksort
    public static void quicksort(int[] arr, int start, int end) {
        if (start < end) {
            int partitionIndex = partition(arr, start, end);
            quicksort(arr, start, partitionIndex - 1);
            quicksort(arr, partitionIndex + 1, end);
        }
    }

    public static int kthSmallestBySorting(int[] arr, int k) {
        quicksort(arr, 0, arr.length - 1);
        return arr[k - 1];
    }

    // ---------------------------------------------------------------------------------------------------------------//

    // Approach 2 - Max Heap
    // Build a Max Heap of the first K elements (index 0 to K-1) -----> O(K)
    // For each element after the Kth element (index K to n - 1), compare it with root of Max Heap -----> O((n-K)logK)
    //      If element is smaller than root of max heap, replace the root with the element and heapifyDown
    //      Otherwise ignore
    // Finally the root element is the Kth smallest element
    // Time complexity - O(K + (n - K)logK)
    // Space complexity - O(K) - To store the max heap array

    // Temporary values, will be changed according to the size of the array given as input (line 142)
    static int size;
    static int[] maxHeapArr;

    // @formatter:off

    private static int getLeftChildIndex(int parentIndex) { return (parentIndex * 2 + 1); }
    private static int getRightChildIndex(int parentIndex) { return (parentIndex * 2 + 2); }

    private static boolean hasLeftChild(int index) { return (getLeftChildIndex(index) < size); }
    private static boolean hasRightChild(int index) { return (getRightChildIndex(index) < size); }

    private static int leftChild(int index) { return maxHeapArr[getLeftChildIndex(index)]; }
    private static int rightChild(int index) { return maxHeapArr[getRightChildIndex(index)]; }

    // @formatter:on

    private static void heapifyDown(int index) {
        while (hasLeftChild(index)) {
            int greaterChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) > leftChild(index)) {
                greaterChildIndex = getRightChildIndex(index);
            }

            if (maxHeapArr[index] > maxHeapArr[greaterChildIndex]) {
                break;
            } else {
                swap(maxHeapArr, greaterChildIndex, index);
            }
            index = greaterChildIndex;
        }
    }

    public static void buildMaxHeap() {
        int startIndex = (maxHeapArr.length / 2) - 1;  // Index of last non leaf node
        for (int i = startIndex; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Returns max element (Root of Max Heap) (without deleting)
    public static int peek() {
        if (size == 0) throw new IllegalStateException();
        return maxHeapArr[0];
    }

    // Helper method required in our algorithm (line 58)
    private static void replaceRootAndHeapifyDown(int item) {
        maxHeapArr[0] = item;
        heapifyDown(0);
    }

    // Does the actual functionality of approach 2 explained above (line 55)
    public static int kthSmallestByMaxHeap(int[] arr, int k) {
        size = k;
        maxHeapArr = Arrays.copyOfRange(arr, 0, k);
        buildMaxHeap();

        for (int i = k; i <= arr.length - 1; i++) {
            if (arr[i] < peek()) {
                replaceRootAndHeapifyDown(arr[i]);
            }
        }

        return peek();
    }

    // ---------------------------------------------------------------------------------------------------------------//

    // Approach 3 - Priority Queue - Collection Framework
    // Same as approach 2 but using Priority Queue from the collection framework instead of manual implementation of heap
    // Time complexity - O(KlogK + (n - K)logK)
    // Space complexity - O(K) - To store the max heap array

    public static int kthSmallestByPriorityQueue(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < k; i++) {
            pq.add(arr[i]);
        }

        for (int i = k; i < arr.length; i++) {
            if (arr[i] < pq.peek()) {
                pq.poll();
                pq.add(arr[i]);
            }
        }

        return pq.peek();
    }

    // ---------------------------------------------------------------------------------------------------------------//

    // Approach 4 - QuickSelect - Optimization over Approach 1 which uses QuickSort
    // This is an optimization of approach 1 which uses quicksort.
    // The idea is to not do complete quicksort, but stop at the point where the pivot is the kth smallest element.
    // Also, not to recur for both left and right side of the pivot (which we do in general quicksort)
    // but, to recur for one of them, according to the position of the pivot
    // ASSUMPTION: ALL ELEMENTS IN INPUT ARRAY ARE DISTINCT
    // Time complexity - O(n)
    // Space complexity - O(K) - To store the max heap array

    public static int kthSmallestByQuickSelect(int[] arr, int start, int end, int k) {
        if (k > 0 && k <= end - start + 1) {
            int partitionIndex = partition(arr, start, end);

            // If position is the same as k, return the element at partitionIndex index
            if (partitionIndex - start == k - 1) {
                return arr[partitionIndex];
            }

            // If partitionIndex is greater than k, recur for the left subarray
            if (partitionIndex - start > k - 1) {
                return kthSmallestByQuickSelect(arr, start, partitionIndex - 1, k);
            } else {
                // Otherwise, recur for the right subarray and refactor the value of k as done below
                return kthSmallestByQuickSelect(arr, partitionIndex + 1, end, k - partitionIndex + start - 1);
            }
        }

        // If k is more than number of elements in array or k <= 0
        return Integer.MAX_VALUE;
    }

    public static void main(String[] args) {
        int[] arr1 = {7, 4, 10, 20, 15};
        int[] arr2 = {7, 4, 10, 20, 15};
        int[] arr3 = {7, 4, 10, 20, 15};
        int[] arr4 = {7, 15, 10, 20, 4};
        int k = 4;

        System.out.println(kthSmallestBySorting(arr1, k)); // 15
        System.out.println(kthSmallestByMaxHeap(arr2, k)); // 15
        System.out.println(kthSmallestByPriorityQueue(arr3, k)); // 15
        System.out.println(kthSmallestByQuickSelect(arr4, 0, arr4.length - 1, k));
    }
}
