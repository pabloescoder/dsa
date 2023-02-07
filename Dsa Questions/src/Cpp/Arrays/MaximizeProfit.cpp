// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <vector>
#include <algorithm> // for min() max()

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Time Complexity: O(n)
// Space Complexity: O(1)

using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit{0};
    int minPrice{prices[0]};
    for (int price : prices)
    {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices); // 5
    return 0;
}