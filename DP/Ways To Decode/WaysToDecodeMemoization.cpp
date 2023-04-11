// https://leetcode.com/problems/decode-ways/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int ways(const string &str, int i, vector<int> &lookup)
{
    int n = str.size();

    if (i == n)
        return 1;
    if (str[i] == '0')
        return 0;
    if (lookup[i] != -1)
        return lookup[i];

    if (i <= n - 2 && (str[i] == '1' || str[i] == '2' && str[i + 1] <= '6'))
        lookup[i] = ways(str, i + 1, lookup) + ways(str, i + 2, lookup);
    else
        lookup[i] = ways(str, i + 1, lookup);
    return lookup[i];
}

int main()
{
    string str = "512810120129";
    vector<int> lookup(str.size(), -1);
    cout << ways(str, 0, lookup);
}