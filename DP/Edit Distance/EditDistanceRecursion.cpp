#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Time Complexity: O(3^(m + n))
// Space Complexity: O(m + n)

// If both the characters at indices s1Ptr and s2Ptr are not equal, then we have 3 different options
// We can insert a character in the first string (that character will be equal to the character in the second string), (s1Ptr, s2Ptr+1)
// We can delete a character from the first string (s1Ptr + 1, s2Ptr)
// Inserting a character in the second string (equal to character in the first thing) is same as above delete case (s1Ptr + 1, s2Ptr)
// Deleting a character from the second string is the same as above inserting case (s1Ptr, s2Ptr + 1)
// Thirdly we can replace a character, in this case both the characters will be made same and hence both will be incremented (s1Ptr+1, s2Ptr+1)
// Let's take an example to understand this
// Current index character will be pointed by _ _
// Str1: _i_ndex
// Str2: _i_nside // Both same, increment both
// Str1: i_n_dex
// Str2: i_n_side // Both same, increment both
// Str1: in_d_ex
// Str2: in_s_ide

// Case 1: Add a char in the first string == Delete a char from the second string == (s1Ptr, s2Ptr+1)
// Str1: ins_d_ex    OR    Str1: in_d_ex
// Str2: ins_i_de    OR    Str2: in_i_de

// OR

// Case 2: Delete a char from the first string == Add a char in the second string == (s1Ptr+1, s2Ptr)
// Str1: in_e_x    OR    Str1: ind_e_x
// Str2: in_s_ide  OR    Str2: ind_s_ide

// OR

// Case 3: Substitute characters to make both same == (s1Ptr + 1, s2Ptr + 1)
// Str1: ind_e_x    OR    Str1: ins_e_x
// Str2: ind_i_de   OR    Str2: ins_i_de
int editDistance(const string &s1, const string &s2, int s1Ptr = 0, int s2Ptr = 0)
{
    if (s1Ptr == s1.size() || s2Ptr == s2.size())
        return ((s1Ptr == s1.size()) ? s2.size() - s2Ptr : s1.size() - s1Ptr);

    if (s1[s1Ptr] == s2[s2Ptr])
        return editDistance(s1, s2, s1Ptr + 1, s2Ptr + 1);
    else
        return 1 + min(
                       min(editDistance(s1, s2, s1Ptr + 1, s2Ptr), editDistance(s1, s2, s1Ptr, s2Ptr + 1)),
                       editDistance(s1, s2, s1Ptr + 1, s2Ptr + 1));
}

int main()
{
    string word1 = "inside";
    string word2 = "index";
    cout << editDistance(word1, word2);
}