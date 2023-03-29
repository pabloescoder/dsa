Coin change (problem)
Given an integer that represents an amount of money and a list of possible coins, find the minimum number of coins to make that amount.

Return -1 if it's possible to make the amount with the given coins.

Example:

input:
amount = 15
possible_coins = [2, 3, 7]

output: 4

explanation: We can make the amount 15 by taking 4 coins only, one coin of value 2, two coins of value 3, and one coin of value 7
2+3+3+7 = 15

Constraints:

amount >= 0
len(possible_coins) >= 1
possible_coins[i] >= 1
