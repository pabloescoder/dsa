Edit distance (problem)
Given two strings word1 and word2, calculate their edit distance.
The edit distance in this problem is defined as the minimum number of insertions, deletions, and substitutions of characters to go from word1 to word2.

Example:

input:
word1 = "inside"
word2 = "index"

output: 3

explanation: To go from "inside" to "index", we can delete the character 's', delete the second character 'i', and insert a character 'x' at the end, in total we need 3 operations
"inside" -> "inide" -> "inde" -> "index"
