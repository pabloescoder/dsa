#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Time Complexity: O(n^3) <--- Can be optimised further by using a trie
// Space Complexity: O(n)
bool wordBreak(string &s, vector<string> &words)
{
    unordered_set<string> wordsSet(words.begin(), words.end());
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i < dp.size(); i++)
        for (int j = 0; j < i; j++)
            if (wordsSet.count(s.substr(j, i - j)) != 0 && dp[j])
            {
                dp[i] = true;
                break;
            }
    return dp[s.size()];
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