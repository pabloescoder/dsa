#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> x;
// int num = 0;

// k = current row where I'm placing the queen
// j = current col where I'm placing the queen
bool place(int k, int j)
{
    for (int i = 1; i <= k - 1; i++)
    {
        // diagonal check = abs(ith col - curr Queen col) == abs(ith row - curr Queen row)
        if ((x[i] == j) || (abs(x[i] - j) == abs(i - k)))
        {
            return false;
        }
    }
    return true;
};

// k is the queen number
void nQueens(int k, int n)
{
    // // Return when 1 answer has been found.
    // if (num == 1)
    //     return;

    // Columns
    for (int j = 1; j <= n; j++)
    {
        if (place(k, j))
        {
            x[k] = j;
            if (k == n)
            {
                // num += 1;
                for (int i = 1; i <= n; i++)
                {
                    cout << x[i] << " ";
                }
                cout << endl;
            }
            else
            {
                nQueens(k + 1, n);
            }
        }
    }
}

void callNQueensAndCountDuration(int n)
{
    // num = 0;
    cout << "n = " << n << endl;
    x = vector<int>(n + 1);
    auto start = chrono::high_resolution_clock::now();
    nQueens(1, n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << "Number of variations possible: " << num << endl;
    cout << "Time: " << duration.count() << " ms" << endl;
    cout << '\n';
}

int main()
{
    callNQueensAndCountDuration(4);
    // callNQueensAndCountDuration(8);
    // callNQueensAndCountDuration(20);
    // callNQueensAndCountDuration(25);
    // callNQueensAndCountDuration(26);
    // callNQueensAndCountDuration(28);
    // callNQueensAndCountDuration(30);
    // callNQueensAndCountDuration(36);
}