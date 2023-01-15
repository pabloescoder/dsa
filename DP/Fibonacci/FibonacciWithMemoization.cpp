#include <iostream>
#include <unordered_map>
using namespace std;

// Memoization is generally implemented recursively

// Time Complexity: O(N)
// Space Complexity: O(N)
long long fibonacci(int n, unordered_map<int, long long> &lookup)
{
    if (n == 0 || n == 1)
        return n;

    if (lookup.count(n) != 0)
    {
        return lookup[n];
    }
    else
    {
        lookup[n] = fibonacci(n - 1, lookup) + fibonacci(n - 2, lookup);
        return lookup[n];
    }
}

int main()
{
    unordered_map<int, long long> lookup;
    cout << fibonacci(92, lookup); // 7540113804746346429
}