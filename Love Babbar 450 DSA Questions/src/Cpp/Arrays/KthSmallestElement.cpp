// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// Reference videos & articles :-
// https://www.youtube.com/watch?v=t0Cq6tVNRBA
// https://www.youtube.com/watch?v=VkKmmwzfIG4
// https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

// Given an array arr[] and an integer K where K is smaller than size of array,
// the task is to find the Kth smallest element in the given array.
// It is given that all array elements are distinct.

#include <iostream>
#include <queue> // For max heap (priority_queue)
using namespace std;

void swap(int *first, int *second);
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

// Approach 1 - Sort the array using Quicksort then return the element at index k-1
// Time Complexity: O(nlogn)
// Space complexity - O(logn) - Because of recursive calls - Assuming average case
int kthSmallestUsingQuicksort(int arr[], int size, int k)
{
    quickSort(arr, 0, size - 1);
    return arr[k - 1];
}

// Approach 2 - Using Max Heap
// Time Complexity: O(K log K + (N - K) log K)
// Space Complexity: O(K)
// Algorithm:-
//  1. Build a max heap of the first K elements of the array (arr[0] to arr[K - 1])
//  2. For every element from K to N - 1, do the following:-
//      i. If the element arr[i] is less than the root of Max Heap, make that element as the root and heapify
//      ii. Else ignore it.
//  3. Finally the root of the max heap is the Kth smallest element.

// Note: To further improve this approach, implement a max heap from scratch and use an optimised buildMaxHeap function
// that can build a maxHeap in O(n). See the Java Code for an example of this.
// Using that the time complexity comes down to O(K + (N - K) log K)
int kthSmallestUsingMaxHeap(int arr[], int size, int k)
{
    // Make Max Heap of first K elements
    priority_queue<int> maxHeap(arr, arr + k);

    // For every element from K to N-1, if greater than the top of max heap, replace the top and heapify
    for (int i = k; i < size; i++)
    {
        if (arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    return maxHeap.top();
}

// Approach 3 - QuickSelect - Optimization over Approach 1 which uses QuickSort
// Time complexity - O(n) <- Average   |   Worst -> O(n^2)
// Space complexity - O(log n) - Recursive calls

// The idea is to not do complete quicksort, but stop at the point where the pivot is the kth smallest element.
// Also, not to recur for both left and right side of the pivot (which we do in general quicksort)
// but, to recur for one of them, according to the position of the pivot
// ASSUMPTION: ALL ELEMENTS IN INPUT ARRAY ARE DISTINCT

// Algorithm:
// In this algorithm pick a pivot element and move it to it’s correct position
// Now, if index of pivot is equal to K then return the value, else if the index of pivot is greater than K,
// then recur for the left subarray, else recur for the right subarray.
// Repeat this process until the element at index K is not found.
int kthSmallestUsingQuickSelect(int arr[], int start, int end, int k)
{
    // If k is smaller than no. of elements in the array
    if (k > 0 && k <= end - start + 1)
    {
        int pivotIndex = partition(arr, start, end);

        // If pivotIndex is the same as k
        if (pivotIndex - start == k - 1)
            return arr[pivotIndex];
        else if (pivotIndex - start > k - 1)
        {
            // pivotIndex is greater - recur for the left subarray
            return kthSmallestUsingQuickSelect(arr, start, pivotIndex - 1, k);
        }
        // Recur for the right subarray, fix K since we are only considering a part of the array
        return kthSmallestUsingQuickSelect(arr, pivotIndex + 1, end, k - pivotIndex + start - 1);
    }

    // Else if k is greater than or equal to the number of elements
    return INT_MAX;
}

// Helper function to call the function with the main logic of QuickSelect
int kthSmallestUsingQuickSelect(int arr[], int size, int k)
{
    return kthSmallestUsingQuickSelect(arr, 0, size - 1, k);
}

int main()
{
    int arr1[]{7, 4, 10, 20, 15};
    int arr2[]{7, 4, 10, 20, 15};
    int arr3[]{7, 4, 10, 20, 15};
    int size{sizeof(arr1) / sizeof(arr1[0])};
    cout << kthSmallestUsingQuicksort(arr1, size, 4) << '\n';   // 15
    cout << kthSmallestUsingMaxHeap(arr2, size, 4) << '\n';     // 15
    cout << kthSmallestUsingQuickSelect(arr3, size, 4) << '\n'; // 15
}

void swap(int *first, int *second)
{
    int temp{*first};
    *first = *second;
    *second = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot{arr[end]};
    int i{start - 1};

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        swap(&arr[i + 1], &arr[end]);
    }
    return i + 1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}