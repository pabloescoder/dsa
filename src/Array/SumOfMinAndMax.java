// https://practice.geeksforgeeks.org/problems/max-min/1

// Time Complexity O(n)
// Space Complexity O(1)

package Array;

public class SumOfMinAndMax {
    public static int findSum(int[] arr) {
        int min = arr[0];
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return min + max;
    }

    public static void main(String[] args) {
        System.out.println(findSum(new int[]{1, 3, 4, 1}));  // 1 + 4 = 5
    }
}
