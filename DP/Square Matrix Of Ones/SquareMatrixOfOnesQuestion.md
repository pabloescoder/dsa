Square matrix of ones (problem)
Given a matrix of ones and zeros, find the area of the greatest square submatrix full of ones.

A square matrix is a matrix whose the number of rows is equal to the number of columns.

Example:

intput:
matrix = [
[0, 0, 1, 1, 1, 0],
[1, 0, 1, 1, 1, 1],
[0, 1, 1, 1, 1, 0],
[1, 1, 1, 1, 0, 1],
[0, 1, 0, 1, 1, 1]
]

output: 9

explanation: (see image)

Constraints:

len(matrix) >= 1
len(matrix[i]) >= 1
matrix[i][j] is equal to 0 or 1
