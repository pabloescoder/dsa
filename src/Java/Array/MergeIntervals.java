// https://leetcode.com/problems/merge-intervals/

package Java.Array;

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;


public class MergeIntervals {
    // Time Complexity - O(nlogn)
    // Space Complexity - O(n)
    public static int[][] merge(int[][] intervals) {
        // If there's only 1 interval, return it as it is
        if (intervals.length <= 1) {
            return intervals;
        }

        // Use the sort method and pass an anonymous comparator to sort the intervals by the interval start
        // Ex: [[1, 3], [3, 4], [0, 2]] will be sorted to [[0, 2], [1, 3], [3, 4]]
        Arrays.sort(intervals, (i1, i2) -> i1[0] - i2[0]);

        List<int[]> output = new ArrayList<>();
        int startIndex = intervals[0][0];
        int endIndex = intervals[0][1];

        for (int[] interval : intervals) {
            if (interval[0] <= endIndex) {  // Intervals are overlapping, move the endIndex if necessary
                endIndex = Math.max(endIndex, interval[1]);
            } else {  // Intervals are disjoint, add the previous interval to the list and set start and end index
                output.add(new int[]{startIndex, endIndex});
                startIndex = interval[0];
                endIndex = interval[1];
            }
        }

        output.add(new int[]{startIndex, endIndex});  // Add the remaining interval that was left after the loop ended
        return output.toArray(int[][]::new);  // Convert List Collection to a 2D array
    }

    public static void main(String[] args) {
        int[][] outputArr = (merge(new int[][]{{1, 3}, {2, 6}, {8, 10}, {15, 18}}));
        for (int[] arr : outputArr) {
            System.out.println(Arrays.toString(arr));
        }
    }
}
