Ways to decode (problem)
A string made of letters can be encoded by replacing each letter by its position in the alphabet (e.g.: ELD -> 5124), but when decoding, a same encoded string can have multiple ways to be decoded (e.g.: 5124 can be decoded as 5 1 2 4 (EABD), or 5 12 4 (ELD), or 5 1 24 (EAX)).

Given an encoded string s made of numbers, find the number of possible ways to decode it by following this decoding map:

1 -> A, 2 -> B, 3 -> C, 4 -> D, 5 -> E, 6 -> F, 7 -> G, 8 -> H, 9 -> I, 10 -> J, 11 -> K, 12 -> L, 13 -> M, 14 -> N, 15 -> O, 16 -> P, 17 -> Q, 18 -> R, 19 -> S, 20 -> T, 21 -> U, 22 -> V, 23 -> W, 24 -> X, 25 -> Y, 26 -> Z

Example:

input:
s = "512810120129"

output: 4

explanation: There are 4 possible ways to decode s:
5 1 2 8 10 1 20 1 2 9
5 1 2 8 10 1 20 12 9
5 12 8 10 1 20 1 2 9
5 12 8 10 1 20 12 9

Constraints:

len(s) >= 1
'0' <= s[i] <= '9'
