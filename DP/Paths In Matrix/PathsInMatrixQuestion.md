https://www.udemy.com/course/dynamic-programming-x/learn/quiz/5350326#questions

Paths in matrix (problem)
Given a matrix where a cell has the value of 1 if it's a wall and 0 if not,
find the number of ways to go from the top-left cell to the bottom-right cell,
knowing that it's not possible to pass from a wall and we can only go to the right or to the bottom.

Example:

input:
matrix = [
[0, 0, 1, 0, 1],
[0, 0, 0, 0, 1],
[0, 0, 1, 0, 0],
[1, 0, 0, 0, 0]
]

output: 7

explanation: https://github.com/pabloescoder/dsa/blob/main/DP/Paths%20In%20Matrix/explanation_of_test_case.png

Constraints:
matrix\[i\]\[j\] can either be 0 or 1
len(matrix) >= 1
len(matrix\[i\]) >= 1
