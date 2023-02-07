#include <iostream>

// Given 2 numbers, swap them without using a temporary variable
using namespace std;

// Using XOR
// By utilising the commutativity and associativity of XOR
// More detail in the comments below
// Time Complexity: O(1)
// Space Complexity: O(1)
void swapNos(int *num1, int *num2)
{
    if (*num1 == *num2) // This method doesn't work if both nums are same, so handle that
        return;

    // Let num1 = a and num2 = b
    *num1 = *num1 ^ *num2; // a = a ^ b
    *num2 = *num1 ^ *num2; // b = a ^ b = (a ^ b) ^ b = a ^ (b ^ b) = a
    *num1 = *num1 ^ *num2; // a = a ^ b = (a ^ b) ^ a = (a ^ a) ^ b = b
}

int main()
{
    int num1 = -5;
    int num2 = 10;

    cout << "Before: " << num1 << " " << num2 << '\n';
    swapNos(&num1, &num2);
    cout << "After: " << num1 << " " << num2;
}