#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Time Complexity: O(n^3) // Size of recursion tree can go up to n^2
// Space Complexity: O(n)
bool wordBreakRec(string &s, unordered_set<string> &wordSet, int i, vector<int> &lookup)
{
    if (i == s.size())
        return true;
    if (lookup[i] != -1)
        return lookup[i];

    for (int j = i + 1; j < s.size() + 1; j++)
        if (wordSet.count(s.substr(i, j - i)) != 0 && wordBreakRec(s, wordSet, j, lookup))
        {
            lookup[i] = true;
            return lookup[i];
        }
    lookup[i] = false;
    return lookup[i];
}

bool wordBreak(string &s, vector<string> &words)
{
    unordered_set<string> wordsSet(words.begin(), words.end());
    vector<int> lookup(s.size(), -1);
    return wordBreakRec(s, wordsSet, 0, lookup);
}

int main()
{
    string s = "catsandogsareanimals";
    vector<string> words = {"cats", "dog", "sand", "and", "cat", "mals", "san", "dogs", "are", "animal", "ani", "og", "sar"};
    // string s = "catsandog";
    // vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    cout << boolalpha;
    cout << wordBreak(s, words);
}