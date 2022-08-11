// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
// Reference: https://www.baeldung.com/cs/minimum-jumps-to-reach-array-end

package Array;

// Given an array of N integers arr[] where each element represents
// the max length of the jump that can be made forward from that element.
// Find the minimum number of jumps to reach the end of the array (starting from the first element).
// If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.
// Time Complexity - O(n)
// Space Complexity - O(1)

// Approach - Greedy
// Keep moving forward as long as it is possible to, once we no longer have any more moves left,
// Jump from the element which gets us the furthest distance possible compared to all the other elements which we've traversed.
// There are 2 things which we keep track of in this approach
//      1. Maximum Reach: It is the furthest index which we can possibly go to using one of the jumps
//      2. Moves: It tracks the number of moves which can be made using the last jump which we did
// Initially we set maximumReach AND remainingMoves to arr[0]. Since we have to make the first jump at index 0.
// Since the first jump is compulsory, jumps is initialised to 1.
// Then iterate over the array, starting from index 0, and update the maximumPosition we can reach accordingly,
// as well as decrease the moves which we can make by 1 in every iteration
// If no more moves are left (moves = 0), then jump from the element which allows us to reach us the maximum distance
// and increment the number of jumps by 1.

public class MinNumOfJumpsToReachEnd {
    public static int minJumps(int[] arr) {

        // If array has only one element, we are already at the end
        if (arr.length == 1) {
            return 0;
        }

        int maximumReach = arr[0];
        int remainingMoves = arr[0];
        int jumps = 1;
        for (int i = 1; i < arr.length - 1; i++) {
            maximumReach = Math.max(maximumReach, arr[i] + i);
            remainingMoves -= 1;

            if (remainingMoves == 0) {
                jumps += 1;
                remainingMoves = maximumReach - i;
            }

            // If at any point remainingMoves becomes negative then we won't be able to reach the end, so return -1
            if (remainingMoves < 0) {
                return -1;
            }
        }

        // If the maximumReach is less than the last index, then we were not able to reach the end, return -1
        if (maximumReach < arr.length - 1) {
            return -1;
        }
        // Otherwise, return the min jumps
        return jumps;
    }

    public static void main(String[] args) {
        System.out.println(minJumps(new int[]{2, 3, 1, 1, 2, 4, 2, 0, 1, 1}));  // 4
    }
}
