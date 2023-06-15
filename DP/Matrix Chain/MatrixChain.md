Matrix chain problem (problem)
We have n matrices and we want to compute their product.
+-

Matrix multiplication is associative, so ABC for example can be calculated as A(BC) or (AB)C.

But A(BC) and (AB)C can require a different number of operations to be computed.

For example if A is a 10x30 matrix, B is a 30x5 matrix, and C is a 5x60, then computing ABC as A(BC) costs 27000 operations, because:

cost(BC) = rows(B) x cols(B) x cols(C) = 30x5x60 = 9000
cost(A(BC)) = rows(A) x cols(A) x cols(C) = 10x30x60 = 18000
total = 9000 + 18000 = 27000

But computing it as (AB)C costs 4500 operations, because:

cost(AB) = rows(A) x cols(A) x cols(B) = 10x30x5 = 1500
cost((AB)C) = rows(A) x cols(B) x cols(C) = 10x5x60 = 3000
total = 1500 + 3000 = 4500

So it's better to compute it as (AB)C, it takes less operations.

(NB: To be able to multiply a matrix A of size n x m by a matrix B of size m x p, the number of columns of A must be equal to the number of rows of B, and the cost of the multiplication is n x m x p, and the result of the product is a matrix of size n x p)

In the Matrix chain multiplication problem, we are given dimensions of n matrices, and we are asked to calculate the minimum number of operations to calculate the product M0*M1*M2\*...

Example:

input:
matrices = [(40, 20), (20, 30), (30, 10), (10, 30), (30, 50)]

output: 49000

explanation: The optimal way of putting parentheses to compute ABCDE is (A(BC))(DE), we calculate BC, then we multiply A by the result, then we calculate DE, then we multiply the result of A(BC) by the result of DE
(NB: A is matrices[0], B is matrices[1], C is matrices[2], D is matrices[3], and E is matrices[4])

cost(BC) = rows(B) x cols(B) x cols(C) = 20x30x10 = 6000
cost(A(BC)) = rows(A) x cols(B) x cols(C) = 40x20x10 = 8000
cost(DE) = rows(D) x cols(D) x cols(E) = 10x30x50 = 15000
cost((A(BC)(DE)) = rows(A) x cols(C) x cols(E) = 40x10x50 = 20000
total = 6000 + 8000 + 15000 + 20000 = 49000

Constraints:

len(matrices) >= 1
len(matrices[i]) = 2
matrices[i][0] = number of rows of the matrix i
matrices[i][1] = number of columns of the matrix i
matrices[i][1] = matrices[i+1][0]
