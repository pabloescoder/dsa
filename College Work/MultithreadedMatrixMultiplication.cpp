#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<int>> &mat);

int matrixSize = 4;
int maxThreads = 4;
int step_i = 0;

vector<vector<int>> matA(matrixSize, vector<int>(matrixSize));
vector<vector<int>> matB(matrixSize, vector<int>(matrixSize));
vector<vector<int>> matC(matrixSize, vector<int>(matrixSize));

void *multi(void *arg)
{
    int i = step_i++; // i denotes row number of resultant matC

    for (int j = 0; j < matrixSize; j++)
        for (int k = 0; k < matrixSize; k++)
            matC[i][j] += matA[i][k] * matB[k][j];
}

// Driver Code
int main()
{
    srand(time(0));

    // Generating random values in matA and matB
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }

    // Displaying matA & matB
    cout << "\nMatrix A\n";
    printMatrix(matA);
    cout << "\nMatrix B\n";
    printMatrix(matB);

    // declaring four threads
    pthread_t threads[maxThreads];

    // Creating four threads, each evaluating its own part
    for (int i = 0; i < maxThreads; i++)
        // Thread id, thread attributes, callback function, args to be passed
        pthread_create(&threads[i], NULL, multi, nullptr);

    // joining and waiting for all threads to complete
    for (int i = 0; i < maxThreads; i++)
        // Which thread to wait for, pointer to variable that will store return value
        pthread_join(threads[i], nullptr);

    // Displaying the result matrix
    cout << "\nMultiplication of A and B\n";
    printMatrix(matC);
}

void printMatrix(vector<vector<int>> &mat)
{
    for (auto vec : mat)
    {
        for (auto elem : vec)
        {
            cout << elem << " ";
        }
        cout << '\n';
    }
}