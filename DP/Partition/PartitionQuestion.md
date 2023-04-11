Partition (problem)
Given an array of strictly positive integers arr, check if we can split it into two subsets that have the same sum of elements.

Example 1:

input:
arr = [4, 5, 3, 2, 5, 1]

output: true

explanation: We can split arr into [4, 3, 2, 1] and [5, 5], and they have the same sum
4+3+2+1 = 5+5 = 10

Example 2:

input:
arr = [5, 6, 2, 3, 8, 1]

output: false

explanation: We can't split arr into two subsets that have the same sum

Constraints:

len(arr) >= 1
arr[i] >= 1
