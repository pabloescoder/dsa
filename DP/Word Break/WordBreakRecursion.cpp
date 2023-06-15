#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// Given a string of length nnn, there are n+1n + 1n+1 ways to split it into two parts.
// At each step, we have a choice: to split or not to split.
// In the worse case, when all choices are to be checked, that results in O(2^n)

// Time Complexity: O(2^n)
// Space Complexity: O(n)
bool wordBreakRec(string &s, unordered_set<string> &wordSet, int i)
{
    if (i == s.size())
        return true;

    for (int j = i + 1; j < s.size() + 1; j++)
        if (wordSet.count(s.substr(i, j - i)) != 0 && wordBreakRec(s, wordSet, j))
            return true;
    return false;
}

bool wordBreak(string &s, vector<string> &words)
{
    unordered_set<string> wordsSet(words.begin(), words.end());
    return wordBreakRec(s, wordsSet, 0);
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