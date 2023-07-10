#include <iostream>
using namespace std;

// First [] can be omitted but remaining need to be specified for passing multi dimensional arrays to functions
// Sizeof doesn't work properly in functions as pointer to the array is passed. So we need to provide the number of rows
// Other dimensions are known from before like 2 colums in arr[][2] so we can use that directly
void print2DimArray(int arr[][3], int rows);
void print3DimArray(int arr[][3][2], int rows);

// Alternatively we can use array of pointers to implement a 2D array
// The array of pointers needs to be made dynamically and is stored in the heap
// Each pointer inside the array of pointers points to another array
// Can have various sized arrays inside the array of pointer, whereas a 2D array has fixed sized arrays
// Ex. {{1, 2}, {3}, {4, 5, 6}} = {p1, p2, p3} || where || p1 -> {1, 2} || p2 -> {3} || p3 -> {4, 5, 6}
void printArrayOfPointers(int **arr, int rows, int cols[]); // Cols is an array because the columns can be variable sized

int main()
{
    // 2D array
    cout << "-----------------------------------------------------------\n";
    cout << "2 Dimensional Arrays and Pointers\n";
    cout << "-----------------------------------------------------------\n";
    int matrix[4][3] = {{1, 2, 3},
                        {5, 6, 7},
                        {9, 10, 11},
                        {13, 14, 15}};

    // To declare a pointer to this 2d array, we need to specify the number of columns
    // when initializing the pointer with the address of matrix
    // Here, ptr will point to an array of 3 rows.
    // matrix will return a pointer to 1D array of 3 integers
    // Initially *ptr = the first array in the 2d array, ie. [1, 2, 3]
    int(*ptr)[3] = matrix;
    cout << "\nmatrix[4][3] = {{1, 2, 3}, \n\t\t{5, 6, 7}, \n\t\t{9, 10, 11}, \n\t\t{13, 14, 15}}\n\n";
    cout << "-> &matrix = " << &matrix << '\n';
    cout << "-> matrix = " << matrix << "\n\n";
    cout << "int(*ptr)[3] = matrix\n";
    cout << "-> ptr = " << ptr << "\n\n";
    cout << "-> *ptr = " << *ptr << '\n';
    cout << "-> ptr[0] = " << ptr[0] << '\n';
    cout << "-> *ptr[0] = " << *ptr[0] << '\n';
    cout << "-> ptr[0][2] = " << ptr[0][2] << '\n';
    cout << "-> *(*(ptr + 0) + 2) = " << *(*(ptr + 0) + 2) << '\n';
    cout << "ptr[0] is equivalent to *(ptr + 0)\n";
    cout << "*ptr[0] is equivalent to *(*(ptr + 0))\n";
    cout << "ptr[0][2] is equivalent to *(*(ptr + 0) + 2)\n\n";

    cout << "ptr[1] = *(ptr + 1) = " << *(ptr + 1) << '\n';
    cout << "*ptr[1] = *(*(ptr + 1)) = " << *(*(ptr + 1)) << '\n';
    cout << "ptr[1][2] = *(*(ptr + 1) + 2) = " << *(*(ptr + 1) + 2) << "\n\n";

    // 3D Array
    cout << "-----------------------------------------------------------\n";
    cout << "3 Dimensional Arrays and Pointers\n";
    cout << "-----------------------------------------------------------\n";
    int threeDim[4][3][2] = {{{10, 20}, {25, 35}, {40, 50}},
                             {{1, 2}, {5, 6}, {8, 9}},
                             {{100, 200}, {250, 350}, {400, 500}},
                             {{-1, -2}, {-5, -6}, {-8, -9}}};

    int(*twoDimPtr)[3][2] = threeDim;
    cout << "\nthreeDim[4][3][2]   = \t{{{10, 20}, {25, 35}, {40, 50}}, \n\t\t\t{{1, 2}, {5, 6}, {8, 9}}, \n\t\t\t{{100, 200}, {250, 350}, {400, 500}}, \n\t\t\t{{-1, -2}, {-5, -6}, {-8, -9}}}\n\n";
    cout << "-> &threeDim = " << &threeDim << '\n';
    cout << "-> threeDim = " << threeDim << "\n\n";
    cout << "int(*twoDimPtr)[3][2] = threeDim\n";
    cout << "-> twoDimPtr = " << twoDimPtr << "\n\n";
    cout << "-> *(*(twoDimPtr + 1) + 2) = " << *(*(twoDimPtr + 1) + 2) << '\n';
    cout << "-> *(*(*(twoDimPtr + 1) + 2)) = " << *(*(*(twoDimPtr + 1) + 2)) << '\n';
    cout << "-> twoDimPtr[1][2][0] = " << *(*(*(twoDimPtr + 1) + 2)) << "\n\n";
    cout << "-> *(*(*twoDimPtr + 2)) = " << *(*(*twoDimPtr + 2)) << '\n';
    cout << "-> twoDimPtr[0][2][0] = " << twoDimPtr[0][2][0] << "\n\n";
    cout << "-> *(*(*(twoDimPtr + 3) + 2) + 1) = " << *(*(*(twoDimPtr + 3) + 2) + 1) << '\n';
    cout << "-> twoDimPtr[3][2][1] = " << twoDimPtr[3][2][1] << '\n';

    cout << "-----------------------------------------------------------\n";
    cout << "Passing Multi Dimensional Arrays to Functions\n";
    cout << "-----------------------------------------------------------\n";
    int rowsInMatrix = sizeof(matrix) / sizeof(matrix[0]);
    print2DimArray(matrix, rowsInMatrix);

    int rowsInThreeDim = sizeof(threeDim) / sizeof(threeDim[0]);
    print3DimArray(threeDim, rowsInThreeDim);

    cout << "-----------------------------------------------------------\n";
    cout << "Array of Pointers\n";
    cout << "-----------------------------------------------------------\n";
    // Can be used to create a 2D array with variable sized inner arrays
    // Arrays need to be dynamically allocated
    // Outer array stores various pointers
    // Each pointer points to an array
    int numRows = 3;
    int numCols[3]; // Since we will create variable sized columns, we need to store it somewhere
    int **arrayOfPtrs = new int *[numRows];

    for (int i = 0; i < numRows; i++)
    {
        arrayOfPtrs[i] = new int[numRows * (i + 1)]; // Creating variable sized inner arrays

        numCols[i] = numRows * (i + 1);
        // Storing values in the inner arrays - Just for demonstration purposes
        for (int j = 0; j < numCols[i]; j++)
        {
            arrayOfPtrs[i][j] = (i + 1) * (j + 1);
        }
    }

    printArrayOfPointers(arrayOfPtrs, numRows, numCols);

    // Cleanup
    // Since we dynamically allocated memory for our Array of Pointers, we need to free it up manually
    for (int i = 0; i < numRows; i++)
    {
        delete[] arrayOfPtrs[i];
    }
    delete[] arrayOfPtrs;
}

void print2DimArray(int arr[][3], int rows)
{
    cout << '\n';
    cout << "Printing 2 Dim Array\n";
    cout << "[\n";
    for (int i = 0; i < rows; i++)
    {
        cout << "  [ ";
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "], \n";
    }
    cout << "]\n";
}

void print3DimArray(int arr[][3][2], int rows)
{
    cout << '\n';
    cout << "Printing 3 Dim Array\n";
    cout << "[\n";
    for (int i = 0; i < rows; i++)
    {
        cout << "  [ ";
        for (int j = 0; j < 3; j++)
        {
            cout << "[ ";
            for (int k = 0; k < 2; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << "], ";
        }
        cout << "],\n";
    }
    cout << "]\n";
}

void printArrayOfPointers(int **arr, int rows, int cols[])
{
    cout << '\n';
    cout << "Printing Array of Pointers\n";
    cout << "[\n";
    for (int i = 0; i < rows; i++)
    {
        cout << "  [ ";
        for (int j = 0; j < cols[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "], \n";
    }
    cout << "]\n";
}