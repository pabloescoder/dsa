#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// n = size of trainDays arr
// Time Complexity: O(3^n)
// Space Complexity: O(n)
int cost(const vector<int> &trainDays, const vector<int> &costs, int i)
{
    int n = trainDays.size();
    if (i == n)
        return 0;

    if (i == n - 1)
        return min({costs[0], costs[1], costs[2]});

    int nextWeekI = i;
    while (nextWeekI < n && trainDays[nextWeekI] < trainDays[i] + 7)
        nextWeekI++;

    int nextMonthI = i;
    while (nextMonthI < n && trainDays[nextMonthI] < trainDays[i] + 30)
        nextMonthI++;

    return min({costs[0] + cost(trainDays, costs, i + 1),
                costs[1] + cost(trainDays, costs, nextWeekI),
                costs[2] + cost(trainDays, costs, nextMonthI)});
}

// n = size of trainDays arr
// Time Complexity: O(3^n)
// Space Complexity: O(n)
int costVariation2(unordered_set<int> &trainDays, const vector<int> &costs, int day, int n)
{
    if (day >= n)
        return 0;
    if (trainDays.count(day) == 0)
        return costVariation2(trainDays, costs, day + 1, n);
    else
        return min({costs[0] + costVariation2(trainDays, costs, day + 1, n),
                    costs[1] + costVariation2(trainDays, costs, day + 7, n),
                    costs[2] + costVariation2(trainDays, costs, day + 30, n)});
}

int main()
{
    vector<int> train_days = {1, 3, 8, 9, 22, 23, 28, 31};
    unordered_set<int> train_days_set(train_days.begin(), train_days.end());
    vector<int> costs = {4, 10, 25};
    int n = 32;
    cout << cost(train_days, costs, 0) << endl;
    cout << costVariation2(train_days_set, costs, 0, n);
}