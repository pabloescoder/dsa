// https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0
// Reference Links :-
// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/

package Array;

// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.
// Union of the two arrays can be defined as the set containing distinct elements from both the arrays.

// IMPORTANT: If there are repetitions, then only one occurrence of element should be printed in the union/intersection.

import java.util.Arrays;
import java.util.HashSet;

public class UnionAndIntersection {

    // UNION
    // Approach 1 - Modified merge method
    // This method assumes that the arrays are sorted
    // If the arrays are not sorted then use Quicksort to sort the arrays then apply the doUnionOnSortedArrays method
    // Union array generated in this approach is automatically sorted

    // Time Complexity (Sorted Arrays as Input): O(M + N) where M & N are the lengths of the two arrays
    // Space Complexity: O(M + N)
    // ---------------------------
    // Time Complexity (Unsorted Arrays as Input): O(MlogM + NlogN) (Quicksort)
    // Space Complexity: O(M + N)

    public static int[] doUnionOnSortedArrays(int[] arr1, int[] arr2) {
        // Max size of union array will be when all elements are distinct in both arrays
        int[] unionArr = new int[arr1.length + arr2.length];
        int arr1Pointer = 0, arr2Pointer = 0, unionArrPointer = 0;

        while (arr1Pointer < arr1.length && arr2Pointer < arr2.length) {
            if (arr1[arr1Pointer] < arr2[arr2Pointer]) {
                // Copy element from arr1 to union array only if it is not already present
                if (unionArrPointer == 0 || unionArr[unionArrPointer - 1] != arr1[arr1Pointer]) {
                    unionArr[unionArrPointer++] = arr1[arr1Pointer++];
                } else {
                    arr1Pointer++;
                }
            } else if (arr1[arr1Pointer] > arr2[arr2Pointer]) {
                // Copy element from arr2 to union array only if it is not already present
                if (unionArrPointer == 0 || unionArr[unionArrPointer - 1] != arr2[arr2Pointer]) {
                    unionArr[unionArrPointer++] = arr2[arr2Pointer++];
                } else {
                    arr2Pointer++;
                }
            } else if (arr1[arr1Pointer] == arr2[arr2Pointer]) {
                // Both elements are equal, insert one to the union array and increment both pointers
                if (unionArrPointer == 0 || unionArr[unionArrPointer - 1] != arr1[arr1Pointer]) {
                    unionArr[unionArrPointer++] = arr1[arr1Pointer++];
                } else {
                    arr1Pointer++;
                }
                arr2Pointer++;
            }
        }

        // Copy remaining elements if any (happens when one array has greater length than the other)
        while (arr1Pointer < arr1.length) {
            if (unionArrPointer == 0 || unionArr[unionArrPointer - 1] != arr1[arr1Pointer]) {
                unionArr[unionArrPointer++] = arr1[arr1Pointer++];
            } else {
                arr1Pointer++;
            }
        }
        while (arr2Pointer < arr2.length) {
            if (unionArrPointer == 0 || unionArr[unionArrPointer - 1] != arr2[arr2Pointer]) {
                unionArr[unionArrPointer++] = arr2[arr2Pointer++];
            } else {
                arr2Pointer++;
            }
        }

        // Remove the extra space from the array
        unionArr = Arrays.copyOf(unionArr, unionArrPointer);
        return unionArr;
    }

    // ---------------------------------------------------------------------------------------------------------------//

    // UNION
    // Approach 2 - HashSet (Collection Framework)
    // Set is a data structure that allows only the distinct elements in it.
    // So, when we put the elements of both the array into the set we will get only the distinct elements
    // Which is basically the union operation over the arrays.

    // Iterate over both arrays from 0 to min(M, N) - 1 and add both all the elements to the set
    // Iterate over the larger array and add remaining elements to the set

    // This works on unsorted as well as sorted arrays
    // However, the final union array is not sorted.

    // Time Complexity: O(max(M, N))
    // Space Complexity: O(M + N)

    public static int[] doUnionUsingSet(int[] arr1, int[] arr2) {
        int M = arr1.length;
        int N = arr2.length;
        int min = Math.min(N, M);

        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < min; i++) {
            set.add(arr1[i]);
            set.add(arr2[i]);
        }

        if (min == M) {
            for (int i = M; i < N; i++) {
                set.add(arr2[i]);
            }
        } else {
            for (int i = N; i < M; i++) {
                set.add(arr1[i]);
            }
        }

        return set.stream().mapToInt(i -> i).toArray();
    }

    // ---------------------------------------------------------------------------------------------------------------//

    // INTERSECTION
    // Approach 1 - Modified merge method
    // This method assumes that the arrays are sorted
    // If the arrays are not sorted then use Quicksort to sort the arrays then apply the doIntersectionOnSortedArrays method
    // Intersection array generated in this approach is automatically sorted

    // Time Complexity (Sorted Arrays as Input): O(M + N) where M & N are the lengths of the two arrays
    // Space Complexity: O(M + N)
    // ---------------------------
    // Time Complexity (Unsorted Arrays as Input): O(MlogM + NlogN) (Quicksort)
    // Space Complexity: O(M + N)

    public static int[] doIntersectionOnSortedArrays(int[] arr1, int[] arr2) {
        // Max size of intersection array will be when all elements are distinct in both arrays
        int[] intersectionArr = new int[arr1.length + arr2.length];
        int arr1Pointer = 0, arr2Pointer = 0, intersectionArrPointer = 0;

        while (arr1Pointer < arr1.length && arr2Pointer < arr2.length) {
            if (arr1[arr1Pointer] < arr2[arr2Pointer]) {
                arr1Pointer++;
            } else if (arr1[arr1Pointer] > arr2[arr2Pointer]) {
                arr2Pointer++;
            } else if (arr1[arr1Pointer] == arr2[arr2Pointer]) {
                // Both elements are equal, insert one to the intersection array and increment both pointers
                if (intersectionArrPointer == 0 || intersectionArr[intersectionArrPointer - 1] != arr1[arr1Pointer]) {
                    intersectionArr[intersectionArrPointer++] = arr1[arr1Pointer++];
                } else {
                    arr1Pointer++;
                }
                arr2Pointer++;
            }
        }

        // Remove the extra space from the array
        intersectionArr = Arrays.copyOf(intersectionArr, intersectionArrPointer);
        return intersectionArr;
    }

    // ---------------------------------------------------------------------------------------------------------------//

    // INTERSECTION
    // Approach 2 - HashSet (Collection Framework)
    // Put all elements of first array in the set
    // Iterate over the elements of the second array, if present in the set then add them to the intersection array

    // This works on unsorted as well as sorted arrays
    // However, the final intersection array is not sorted.

    // Time Complexity: O(M + N) (Assuming that hash table insert & search take O(1))
    // Space Complexity: O(M + N)

    public static int[] doIntersectionUsingSet(int[] arr1, int[] arr2) {
        int M = arr1.length;
        int N = arr2.length;
        int min = Math.min(M, N);

        HashSet<Integer> set = new HashSet<>();
        int[] intersectionArr = new int[arr1.length + arr2.length];
        int nextFreePosition = 0;

        for (int item : (min == M ? arr1 : arr2)) {
            set.add(item);
        }
        for (int item : (min == M ? arr2 : arr1)) {
            if (set.contains(item)) {
                intersectionArr[nextFreePosition++] = item;
            }
        }

        // Remove extra space
        intersectionArr = Arrays.copyOf(intersectionArr, nextFreePosition);

        // Remove duplicates
        HashSet<Integer> intersectionSet = new HashSet<>();
        for (int item : intersectionArr) {
            intersectionSet.add(item);
        }

        return intersectionSet.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {
        // UNION
        // If arrays are unsorted, sort them using quicksort before using doUnionOnSortedArrays
        // Final union array is automatically sorted
        int[] arr1 = {1, 6, 25, 32, 54, 85, 85};
        int[] arr2 = {2, 85, 85};
        System.out.println(Arrays.toString(doUnionOnSortedArrays(arr1, arr2))); // [1, 2, 6, 25, 32, 54, 85]

        // UNION
        // Works on unsorted as well as sorted arrays
        // However final union array is not sorted in this approach
        int[] arr3 = {6, 1, 85, 32, 25, 85, 54};
        int[] arr4 = {85, 2, 85};
        System.out.println(Arrays.toString(doUnionUsingSet(arr3, arr4))); // [32, 1, 2, 85, 6, 54, 25]


        // INTERSECTION
        // If arrays are unsorted, sort them using quicksort before using doIntersectionOnSortedArrays
        // Final intersection array is automatically sorted
        int[] arr5 = {1, 6, 25, 32, 54, 85, 85};
        int[] arr6 = {2, 85, 85};
        System.out.println(Arrays.toString(doIntersectionOnSortedArrays(arr5, arr6))); // [85]

        // INTERSECTION
        // Works on unsorted as well as sorted arrays
        // However final intersection array is not sorted in this approach
        int[] arr7 = {6, 1, 85, 32, 25, 85, 54};
        int[] arr8 = {85, 2, 85};
        System.out.println(Arrays.toString(doIntersectionUsingSet(arr7, arr8))); // [85]
    }
}
