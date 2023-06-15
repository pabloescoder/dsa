#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Time Complexity: O(2^(n+m))
// Space Complexity: O(m+n)
int scs(const string &str1, const string &str2, int s1Ptr, int s2Ptr)
{
    if (s1Ptr == str1.size() || s2Ptr == str2.size())
    {
        if (s1Ptr == str1.size())
            return str2.size() - s2Ptr;
        else
            return str1.size() - s1Ptr;
    }
    else if (str1[s1Ptr] == str2[s2Ptr])
        return 1 + scs(str1, str2, s1Ptr + 1, s2Ptr + 1);
    else
        return 1 + min(scs(str1, str2, s1Ptr + 1, s2Ptr), scs(str1, str2, s1Ptr, s2Ptr + 1));
}

int main()
{
    string s1 = "abdacebfcab";
    string s2 = "acebfca";
    cout << scs(s1, s2, 0, 0);
}