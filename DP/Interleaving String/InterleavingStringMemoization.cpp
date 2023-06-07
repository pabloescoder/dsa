#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
bool inter(string &s1, string &s2, string &s3, int s1P, int s2P, vector<vector<int>> &lookup)
{
    if (s1.size() + s2.size() != s3.size())
        return false;
    if (s1P == s1.size() && s2P == s2.size())
        return true;
    if (s3[s1P + s2P] != s1[s1P] && s3[s1P + s2P] != s2[s2P])
        return false;
    if (lookup[s1P][s2P] != -1)
        return lookup[s1P][s2P];

    if (s3[s1P + s2P] == s1[s1P] && s3[s1P + s2P] == s2[s2P])
        lookup[s1P][s2P] = (inter(s1, s2, s3, s1P + 1, s2P, lookup) || inter(s1, s2, s3, s1P, s2P + 1, lookup));
    else if (s3[s1P + s2P] == s1[s1P])
        lookup[s1P][s2P] = inter(s1, s2, s3, s1P + 1, s2P, lookup);
    else
        lookup[s1P][s2P] = inter(s1, s2, s3, s1P, s2P + 1, lookup);
    return lookup[s1P][s2P];
}

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    // string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // string s3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<vector<int>> lookup(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << boolalpha;
    cout << inter(s1, s2, s3, 0, 0, lookup);
}