Word break (problem)
Given a string s and a list of words, check if we can break s into words from the list (A same word can be used multiple times).

Example:

input:
s = "catsandogsareanimals"
words = ["cats", "dog", "sand", "and", "cat", "mals", "san", "dogs", "are", "animal", "ani", "og", "sar"]

output: true

explanation: s is also equal to "cat"+"san"+"dogs"+"are"+"ani"+"mals", and all of these parts are in words

Constraints:

len(s) >= 1
len(words) >= 1
len(words[i]) >= 1
