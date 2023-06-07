#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// a = 0, e = 1, i = 2, o = 3, u = 4
// Time Complexity: O(n)
// Space Complexity: O(n)
int count(int n, char c, vector<vector<int>> &lookup, vector<char> &vowels, unordered_map<char, int> &charMap)
{
    if (n == 0)
        return 1;
    if (lookup[n][charMap[c]] != -1)
        return lookup[n][charMap[c]];

    int num = 0;
    for (int vowel : vowels)
        if (c <= vowel)
            num += count(n - 1, vowel, lookup, vowels, charMap);
    lookup[n][charMap[c]] = num;
    return lookup[n][charMap[c]];
}

int main()
{
    // int n = 2;
    int n = 9;
    vector<vector<int>> lookup(n + 1, vector<int>(5, -1));
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> charMap = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    cout << count(n, ' ', lookup, vowels, charMap);
}