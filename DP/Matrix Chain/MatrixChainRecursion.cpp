// https://www.udemy.com/course/dynamic-programming-x/learn/lecture/28935332

#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;

// Time Complexity: O(3^n)
// Space Complexity: O(n)
int chain(vector<pair<int, int>> &matrices, int i, int j)
{
    if (i == j) // Only 1 remaining matrix
        return 0;

    int minSteps = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int currSteps = matrices[i].first * matrices[k].second * matrices[j].second;
        minSteps = min(minSteps, currSteps + chain(matrices, i, k) + chain(matrices, k + 1, j));
    }
    return minSteps;
}

int main()
{
    vector<pair<int, int>> matrices = {{40, 20}, {20, 30}, {30, 10}, {10, 30}, {30, 50}};
    cout << chain(matrices, 0, matrices.size() - 1);
}