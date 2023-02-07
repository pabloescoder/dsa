// https://leetcode.com/problems/merge-intervals/
#include <iostream>
#include <vector>
#include <algorithm>

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the intervals in the input.
// Example - 1
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Example - 2
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Time Complexity: O(NlogN)
// Space Complexity: O(logN)
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // Sort the intervals in ascending order
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (vector<int> interval : intervals)
    {
        // If the merged vector is empty or if the current interval does not overlap with the previous,
        // append the current interval to the merged intervals vector
        if (merged.empty() || merged.back()[1] < interval[0])
        {
            merged.push_back(interval);
        }
        else if (merged.back()[1] >= interval[0])
        {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = merge(intervals); // [[1, 6], [8, 10], [15, 18]]

    // Printing the output
    cout << '[';
    for (vector<int> interval : merged)
    {
        if (interval == merged.back())
        {
            cout << "[" << interval[0] << ", " << interval[1] << ']';
        }
        else
        {
            cout << "[" << interval[0] << ", " << interval[1] << "], ";
        }
    }
    cout << ']';
    return 0;
}