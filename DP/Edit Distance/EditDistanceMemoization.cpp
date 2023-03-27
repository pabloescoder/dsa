#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
int editDistance(const string &s1, const string &s2, int s1Ptr, int s2Ptr, vector<vector<int>> &lookup)
{
    if (s1Ptr == s1.size() || s2Ptr == s2.size())
        return ((s1Ptr == s1.size()) ? s2.size() - s2Ptr : s1.size() - s1Ptr);

    if (lookup[s1Ptr][s2Ptr] != -1)
        return lookup[s1Ptr][s2Ptr];

    if (s1[s1Ptr] == s2[s2Ptr])
        lookup[s1Ptr][s2Ptr] = editDistance(s1, s2, s1Ptr + 1, s2Ptr + 1, lookup);
    else // if (s1[s1Ptr] != s2[s2Ptr])
        lookup[s1Ptr][s2Ptr] = 1 + min(
                                       min(editDistance(s1, s2, s1Ptr + 1, s2Ptr, lookup), editDistance(s1, s2, s1Ptr, s2Ptr + 1, lookup)),
                                       editDistance(s1, s2, s1Ptr + 1, s2Ptr + 1, lookup));
    return lookup[s1Ptr][s2Ptr];
}

int main()
{
    string word1 = "inside";
    string word2 = "index";
    vector<vector<int>> lookup(word1.size(), vector<int>(word2.size(), -1));
    cout << editDistance(word1, word2, 0, 0, lookup);
}