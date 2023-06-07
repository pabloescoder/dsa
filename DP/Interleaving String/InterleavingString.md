Interleaving string (problem)
Given 3 strings s1, s2, and s3, check if s3 can be formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn

t = t1 + t2 + ... + tm

|n - m| <= 1

The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

Example:

input:
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"

output: true

explanation:
s1 = "aabcc" = "aa" + "bc" + "c"
s2 = "dbbca" = "dbbc" + "a"
s3 = "aadbbcbcac" = "aa" + "dbbc" + "bc" + "a" + "c"
You can see that we could make s3 by taking "aa" from s1, "dbbc" from s2, "bc" from s1, "a" from s2, and "c" from s1
