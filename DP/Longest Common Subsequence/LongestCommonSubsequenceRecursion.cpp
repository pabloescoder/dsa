#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// The max height of the recursion tree is m + n, and at every node,
// The max number of calls made are 2
// This gives an upper bound time complexity of O(2^(m+n))

// Time Complexity: O(2^(m+n))
// Space Complexity: O(m + n)
int lcs(const string &s1, const string &s2, int index1, int index2)
{
    if (index1 == s1.size() || index2 == s2.size())
        return 0;

    else if (s1[index1] == s2[index2])
        return 1 + lcs(s1, s2, index1 + 1, index2 + 1);
    else
        return max(lcs(s1, s2, index1 + 1, index2), lcs(s1, s2, index1, index2 + 1));
}

int main()
{
    string s1 = "abdacbab";
    string s2 = "acebfca";
    cout << lcs(s1, s2, 0, 0);
}