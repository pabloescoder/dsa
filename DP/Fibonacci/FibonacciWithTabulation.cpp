#include <iostream>
#include <unordered_map>
using namespace std;

// Tabulation is generally implemented iteratively

// Time Complexity: O(N)
// Space Complexity: O(N) // This can be further optimised. See below function.
long long fibonacciTabulation(int n)
{
    // Create an array of size n + 1 to store the values dp[n] = fib[n]
    // Can also use std array instead of manually managing memory
    long long *dp = new long long[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    // Tabulation - Bottom Up
    // Iterate over the dp array and calculate the next fibonacci number dp[n] = dp[n-1] + dp[n-2]
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    long long res = dp[n];
    delete[] dp;
    return res;
}

// Time Complexity: O(N)
// Space Complexity: O(1) --- More optimised compared to prev function
long long fibonacciTabulationOptimised(int n)
{
    // At each moment while calculating the next fibo number using tabulation, we just need 2 things
    // The prev fibo number and the prev prev fibo number
    // So we can optimise space by using 3 variables, curr, prev, prevPrev instead of an array
    long long prevPrev, prev, curr;
    prevPrev = 0;
    prev = 1;

    for (int i = 2; i < n + 1; i++)
    {
        curr = prevPrev + prev;
        prevPrev = prev;
        prev = curr;
    }
    return curr;
}

int main()
{
    cout << fibonacciTabulation(92) << endl;
    cout << fibonacciTabulationOptimised(92);
}