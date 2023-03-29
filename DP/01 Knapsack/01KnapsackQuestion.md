0-1 knapsack (problem)
Given the value and the weight of each one of n items, we want to maximize the value of items we take in our knapsack without exceeding its capacity k. You are asked to find the maximum total value that we can get without exceeding a total weight of k.

Note that each item can be took at most once.

Example:

input:
values = [20, 30, 15, 25, 10]
weights = [6, 13, 5, 10, 3]
k = 20

output: 55

explanation: The maximum total value that we can get is 55, by taking items 0, 3, and 4, their total weight doesn't exceed k
values[0]+values[3]+values[4] = 20+25+10 = 55
weights[0]+weights[3]+weights[4] = 6+10+3 = 19 <= 20

Constraints:

len(values) == len(weights)
len(values) >= 1
k >= 0
values[i] >= 0
weights[i] > 0
