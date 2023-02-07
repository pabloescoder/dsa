#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}

int main()
{
    int num1 = 20;       // 10100 ---> 2
    int num2 = 10000;    // 10011100010000 ---> 5
    int num3 = 98874312; // 101111001001011001111001000 ---> 14

    cout << num1 << ": " << countSetBits(num1) << '\n'; // 2
    cout << num2 << ": " << countSetBits(num2) << '\n'; // 5
    cout << num3 << ": " << countSetBits(num3) << '\n'; // 14
}