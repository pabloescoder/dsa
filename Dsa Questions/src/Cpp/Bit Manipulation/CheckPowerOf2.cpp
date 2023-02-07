#include <iostream>

// Given a number, check whether it is a power of 2 or not.
using namespace std;

// Count the number of set bits, if it is 1 then the number is a power of 2 otherwise not.
// Time Complexity: O(log N)
// Space Complexity: O(1)
bool checkPowerOf2UsingBitCount(int num)
{
    int cnt = 0;
    while (num != 0)
    {
        cnt += (num & 1);
        num = num >> 1;
    }
    return (cnt == 1);
}

// Brian Kernighan’s algorithm
// Take the AND of n and n-1
// Whenever we subtract 1 from a number, all the bits from its rightmost 1 (inclusive) get flipped
// So lets say we have 4 (100) after subtracting 1 we get 3 (011)
// We can then take the AND of both numbers, if it is 0, the number is a power of 2.
// Time Complexity: O(1)
// Space Complexity: O(1)
bool checkPowerOf2UsingSubAND(int num)
{
    // This doesn't work for num = 0 because we will get a negative number that is stored in 2's complement
    // So handle that.
    return (num && !(num & num - 1));
}

int main()
{
    cout << boolalpha;
    cout << 1 << " " << checkPowerOf2UsingBitCount(1) << " " << checkPowerOf2UsingSubAND(1) << endl;
    cout << 32 << " " << checkPowerOf2UsingBitCount(32) << " " << checkPowerOf2UsingSubAND(32) << endl;
    cout << 300 << " " << checkPowerOf2UsingBitCount(300) << " " << checkPowerOf2UsingSubAND(300) << endl;
    cout << 1073741824 << " " << checkPowerOf2UsingBitCount(1073741824) << " " << checkPowerOf2UsingSubAND(1073741824) << endl; // 2^30
    cout << 123456789 << " " << checkPowerOf2UsingBitCount(123456789) << " " << checkPowerOf2UsingSubAND(123456789) << endl;
}