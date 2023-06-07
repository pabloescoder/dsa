#include <iostream>
#include <string>
using namespace std;

// Time Complexity: O(2^(n+m))
// Space Complexity: O(n + m)

bool inter(string &s1, string &s2, string &s3, int s1P, int s2P)
{
    if (s1.size() + s2.size() != s3.size())
        return false;
    if (s1P == s1.size() && s2P == s2.size())
        return true;
    if (s3[s1P + s2P] != s1[s1P] && s3[s1P + s2P] != s2[s2P])
        return false;

    if (s3[s1P + s2P] == s1[s1P] && s3[s1P + s2P] == s2[s2P])
        return (inter(s1, s2, s3, s1P + 1, s2P) || inter(s1, s2, s3, s1P, s2P + 1));
    else if (s3[s1P + s2P] == s1[s1P])
        return inter(s1, s2, s3, s1P + 1, s2P);
    else
        return inter(s1, s2, s3, s1P, s2P + 1);
}

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << boolalpha;
    cout << inter(s1, s2, s3, 0, 0);
}