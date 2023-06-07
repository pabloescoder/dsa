#include <iostream>
#include <cmath>
using namespace std;

// We can use combinatorics
// We'll use the formula for combinations with repetitions
// Why combinations and not permutations?
// Because the strings are in a sorted order, so even if we have three vowels 'a', 'a', 'e'
// The permutations are: 'aae', 'aea', 'eaa' === 3
// The combinations are: 'aae' === 'aea' === 'eaa' === 1
// Since we want only the sorted order, all 3 permutations will be grouped under 1 combination
// Hence we take combinations with repetition
// The formula is (n + r - 1)! / (r! * (n - 1)!)
// Where n is 5, and r is size of string
// n = total number of elements in a set
// r = number of elements that can be selected from a set
// The formula is
//    (n + r - 1)! / (r! * (n - 1)!)
//  = (5 + r - 1)! / (r! * (5 - 1)!)
//  = (4 + r)! / (r! * 24)
//  = (4 + r) * (3 + r) * (2 + r) * (1 + r) / 24
// r = number of elements that can be selected from a set = argument n in the function

// Time Complexity: O(1)
// Space Complexity: O(1)
int count(int n)
{
    return ((n + 4) * (n + 3) * (n + 2) * (n + 1)) / 24;
}

int main()
{
    // int n = 2;
    int n = 9;
    cout << count(n);
}