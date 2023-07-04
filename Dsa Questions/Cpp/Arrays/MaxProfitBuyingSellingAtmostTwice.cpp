// https://practice.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1
#include <iostream>
#include <algorithm>

// In daily share trading, a buyer buys shares in the morning and sells them on the same day.
// If the trader is allowed to make ATMOST 2 transactions in a day,
// whereas the second transaction can only start after the first one is complete (Buy -> sell -> Buy -> sell).
// Given stock prices throughout the day, find out the maximum profit that a share trader could have made.
// Example 1 :-
// Input:   price[] = {10, 22, 5, 75, 65, 80}
// Output:  87
// Trader earns 87 as sum of 12, 75
// Buy at 10, sell at 22,
// Buy at 5 and sell at 80

// Example 2:-
// Input:   price[] = {90, 80, 70, 60, 50}
// Output:  0
// Not possible to earn.
using namespace std;

// Approach 1 - Dynamic Programming
// 1) Create a table profit[0..n-1] and initialize all values in it 0.
// 2) Traverse price[] from right to left and update profit[i] such that profit[i] stores maximum profit achievable from one transaction in subarray price[i..n-1]
// 3) Traverse price[] from left to right and update profit[i] such that profit[i] stores maximum profit such that profit[i] contains maximum achievable profit from two transactions in subarray price[0..i].
// 4) Return profit[n-1]
// Time complexity: O(N)
// Auxiliary space: O(N)
int maxProfitWithDp(int price[], int n)
{
    // Create an array of size n to store the profits, initialize all elements to 0
    int *profit{new int[n]};
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    /*
    Get the maximum profit with only one transaction allowed. After this loop,
    profit[i] contains maximum profit from price[i..n-1] using at most one transaction.
    */
    int max_price = price[n - 1];
    int maxPrice{price[n - 1]};
    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i] > maxPrice)
            maxPrice = price[i];

        // we can get profit[i] by taking maximum of:
        // a) previous maximum, i.e., profit[i+1]
        // b) profit by buying at price[i] and selling at max_price
        profit[i] = max(profit[i + 1], maxPrice - price[i]);
    }

    /*
    Get the maximum profit with two transactions allowed
    After this loop, profit[n-1] contains the result
    */
    int minPrice{price[0]};
    for (int i = 1; i < n; i++)
    {
        if (price[i] < minPrice)
            minPrice = price[i];

        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - minPrice));
    }

    int result = profit[n - 1];
    delete[] profit; // To avoid memory leak
    return result;
}

// Approach 2
// Initialize four variables for taking care of the first buy, first sell, second buy, second sell.
// Set first buy and second buy as INT_MIN and first and second sell as 0.
// This is to ensure to get profit from transactions.
// Iterate through the array and return the second sell as it will store maximum profit.
// Time Complexity: O(N)
// Space Complexity: O(1)
int maxProfit(int price[], int n)
{
    int firstBuy = INT_MIN;
    int firstSell = 0;
    int secondBuy = INT_MIN;
    int secondSell = 0;

    for (int i = 0; i < n; i++)
    {
        // For this approach, remember that every time we buy, we are subtracting from the total profit,
        // and every time we sell, we are adding to the total profit.
        // In the end, secondSell stores the total profit.
        firstBuy = max(firstBuy, -price[i]); // we set prices to negative, so the calculation of profit will be convenient
        firstSell = max(firstSell, firstBuy + price[i]);
        secondBuy = max(secondBuy, firstSell - price[i]); // we can buy the second only after first is sold
        secondSell = max(secondSell, secondBuy + price[i]);
    }

    return secondSell;
}

int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price) / sizeof(price[0]);
    cout << maxProfitWithDp(price, n) << '\n'; // 100
    cout << maxProfit(price, n) << '\n';       // 100
    return 0;
}