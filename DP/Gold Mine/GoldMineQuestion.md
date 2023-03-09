Gold mine (problem)
Given a mine of n rows and m columns where mine[i][j] represents the amount of gold that is present there, we want to enter from the top of the mine and take as much gold as possible when exiting from the bottom, knowing that we can only move to the bottom, to the bottom-left, or to the bottom-right. We can exit from anywhere from the last row.

Example:

input:
mine = [
[3, 2, 12, 15, 10],
[6, 19, 7, 11, 17],
[8, 5, 12, 32, 21],
[3, 20, 2, 9, 7]
]

output: 73

explanation: 15+17+32+9 = 73

Constraints:

len(matrix) >= 1
len(matrix[i]) >= 1
matrix[i][j] >= 0
