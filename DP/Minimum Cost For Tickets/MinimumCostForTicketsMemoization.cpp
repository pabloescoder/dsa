#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// n = size of trainDays arr
// Time Complexity: O(n)
// Space Complexity: O(n)
int cost(const vector<int> &trainDays, const vector<int> &costs, int i, vector<int> &lookup)
{
    int n = trainDays.size();
    if (i == n)
        return 0;
    if (i == n - 1)
        return min({costs[0], costs[1], costs[2]});
    if (lookup[i] != -1)
        return lookup[i];

    int nextWeekI = i;
    while (nextWeekI < n && trainDays[nextWeekI] < trainDays[i] + 7)
        nextWeekI++;

    int nextMonthI = i;
    while (nextMonthI < n && trainDays[nextMonthI] < trainDays[i] + 30)
        nextMonthI++;

    lookup[i] = min({costs[0] + cost(trainDays, costs, i + 1, lookup),
                     costs[1] + cost(trainDays, costs, nextWeekI, lookup),
                     costs[2] + cost(trainDays, costs, nextMonthI, lookup)});
    return lookup[i];
}

// n = size of trainDays arr
// Time Complexity: O(n)
// Space Complexity: O(n)
int costVariation2(unordered_set<int> &trainDays, const vector<int> &costs, int day, int n, vector<int> &lookup)
{
    if (day >= n)
        return 0;
    if (lookup[day] != -1)
        return lookup[day];
    if (trainDays.count(day) == 0)
        lookup[day] = costVariation2(trainDays, costs, day + 1, n, lookup);
    else
        lookup[day] = min({costs[0] + costVariation2(trainDays, costs, day + 1, n, lookup),
                           costs[1] + costVariation2(trainDays, costs, day + 7, n, lookup),
                           costs[2] + costVariation2(trainDays, costs, day + 30, n, lookup)});
    return lookup[day];
}

int main()
{
    vector<int> train_days = {1, 3, 8, 9, 22, 23, 28, 31};
    unordered_set<int> train_days_set(train_days.begin(), train_days.end());
    vector<int> costs = {4, 10, 25};
    int n = 32;
    vector<int> lookup(n, -1);
    vector<int> lookup2(n, -1);
    cout << cost(train_days, costs, 0, lookup) << endl;
    cout << costVariation2(train_days_set, costs, 0, n, lookup);
}