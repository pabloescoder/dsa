Ways to climb (problem)
Given a stairs with n steps and a list of possible ways to jump (for example if jumps[i] = 4 then it's possible to jump by 4 steps), find the total number of ways to reach the nth step starting from the floor.

Example:

input:
n = 10
jumps = [2, 4, 5, 8]

output: 11

explanation: We have 11 possible ways to reach the step 10 starting from the floor are:
2 2 2 2 2 (jump by 2 steps, then 2 steps, then 2 steps, then 2 steps, then 2 steps)
2 2 2 4 (jump by 2 steps, then 2 steps, then 2 steps, then 4 steps)
2 2 4 2 (jump by 2 steps, then 2 steps, then 4 steps, then 2 steps)
2 4 2 2 (jump by 2 steps, then 4 steps, then 2 steps, then 2 steps)
4 2 2 2 (jump by 4 steps, then 2 steps, then 2 steps, then 2 steps)
2 4 4 (jump by 2 steps, then 4 steps, then 4 steps)
4 2 4 (jump by 4 steps, then 2 steps, then 4 steps)
4 4 2 (jump by 4 steps, then 4 steps, then 2 steps)
5 5 (jump by 5 steps, then 5 steps)
2 8 (jump by 2 steps, then 8 steps)
8 2 (jump by 8 steps, then 2 steps)

Constraints:

n >= 1
len(jumps) >= 1
jumps[i] >= 1
