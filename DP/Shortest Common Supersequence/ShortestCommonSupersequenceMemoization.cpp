#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
int scs(const string &str1, const string &str2, int s1Ptr, int s2Ptr, vector<vector<int>> &lookup)
{
    if (s1Ptr == str1.size() || s2Ptr == str2.size())
    {
        if (s1Ptr == str1.size())
            return str2.size() - s2Ptr;
        else
            return str1.size() - s1Ptr;
    }
    if (lookup[s1Ptr][s2Ptr] != -1)
        return lookup[s1Ptr][s2Ptr];
    else if (str1[s1Ptr] == str2[s2Ptr])
        lookup[s1Ptr][s2Ptr] = 1 + scs(str1, str2, s1Ptr + 1, s2Ptr + 1, lookup);
    else
        lookup[s1Ptr][s2Ptr] = 1 + min(scs(str1, str2, s1Ptr + 1, s2Ptr, lookup), scs(str1, str2, s1Ptr, s2Ptr + 1, lookup));
    return lookup[s1Ptr][s2Ptr];
}

int main()
{
    // string s1 = "abdacebfcab";
    // string s2 = "acebfca";
    string s1 = "abac";
    string s2 = "cab";
    vector<vector<int>> lookup(s1.size(), vector<int>(s2.size(), -1));
    cout << scs(s1, s2, 0, 0, lookup);
}