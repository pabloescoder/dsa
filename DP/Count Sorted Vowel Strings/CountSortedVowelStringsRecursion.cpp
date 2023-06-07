#include <iostream>
#include <vector>
using namespace std;
// For time complexity explanation using mathematics, refer to:-
// https://www.udemy.com/course/dynamic-programming-x/learn/lecture/28771472

// Backtracking Solution
// Time Complexity: O(n^5)
// Space Complexity: O(n)
// Shorter code for the same approach written below
int count(int n, int i, char c)
{
    if (i == n)
        return 1;
    if (i == 0 || c == 'a')
        return (count(n, i + 1, 'a') + count(n, i + 1, 'e') +
                count(n, i + 1, 'i') + count(n, i + 1, 'o') +
                count(n, i + 1, 'u'));
    else if (c == 'e')
        return (count(n, i + 1, 'e') + count(n, i + 1, 'i') +
                count(n, i + 1, 'o') + count(n, i + 1, 'u'));
    else if (c == 'i')
        return (count(n, i + 1, 'i') + count(n, i + 1, 'o') +
                count(n, i + 1, 'u'));
    else if (c == 'o')
        return (count(n, i + 1, 'o') + count(n, i + 1, 'u'));
    else // if (c == 'u')
        return count(n, i + 1, 'u');
}

// Backtracking Solution
// Time Complexity: O(n^5)
// Space Complexity: O(n)
int countConcise(int n, char c, vector<char> &vowels)
{
    if (n == 0)
        return 1;

    int num = 0;
    for (char vowel : vowels)
        if (c <= vowel)
            num += countConcise(n - 1, vowel, vowels);
    return num;
}

int main()
{
    // int n = 2;
    int n = 9;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    cout << count(n, 0, ' ') << endl;
    cout << countConcise(n, ' ', vowels);
}