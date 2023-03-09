#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Size of s1 = m, Size of s2 = n. Total subproblems are m * n, time taken to solve 1 subproblem is O(1)
// Space complexity = Space of non memoised + Lookup size = O(n+m) (Call Stack) + O(nm) (Lookup) = O(nm)

// Time Complexity: O(mn)
// Space Complexity: O(mn)
int lcs(const string &s1, const string &s2, int index1, int index2, int **lookup)
{
    if (index1 == s1.length() || index2 == s2.length())
        return 0;

    if (lookup[index1][index2] != -1)
        return lookup[index1][index2];

    if (s1[index1] == s2[index2])
        lookup[index1][index2] = 1 + lcs(s1, s2, index1 + 1, index2 + 1, lookup);
    else
        lookup[index1][index2] = max(lcs(s1, s2, index1 + 1, index2, lookup), lcs(s1, s2, index1, index2 + 1, lookup));
    return lookup[index1][index2];
}

int main()
{
    string s1 = "abdacbab";
    string s2 = "acebfca";
    int **lookup = new int *[s1.size()];
    for (int i = 0; i < s1.size(); i++)
    {
        lookup[i] = new int[s2.size()];
        fill_n(lookup[i], s2.size(), -1);
    }
    cout << lcs(s1, s2, 0, 0, lookup);

    for (int i = 0; i < s1.size(); i++)
        delete[] lookup[i];
    delete[] lookup;
}