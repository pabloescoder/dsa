#include <iostream>

// Given a set of numbers where all elements occur an even number of times except one number, find the odd occurring number.
using namespace std;
void printArr(int *arr, int size);

// One approach is using a unordered_set to store the count of each number and return num having odd count
// Another better approach is by using the XOR (^) operator.
// XOR of a number with itself is always 0. We can use this property to our advantage.
// XOR is associative: a ^ (b ^ c) == (a ^ b) ^ c ;;; and also commutative: a ^ b = b ^ a
// The odd number will be XOR-ed odd number of times. Rest all will be XOR-ed even number of times.
// So all the even occurring numbers will eventually make result 0. And the odd occuring number will be stored in res finally.
// Time Complexity: O(N)
// Space Complexity: O(1)
int findOddOccurringNumber(int *arr, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
        res = res ^ arr[i]; // res ^= arr[i]
    return res;
}

int main()
{
    int arr[] = {12, 12, 14, 90, 14, 14, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The odd occurring element in ";
    printArr(arr, n);
    cout << " is: " << findOddOccurringNumber(arr, n) << '\n';

    int arr2[] = {-1, -2, -3, -4, -4, -4, -3, -2, -1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "The odd occurring element in ";
    printArr(arr2, n2);
    cout << " is: " << findOddOccurringNumber(arr2, n2);
}

void printArr(int *arr, int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << ((i != size - 1) ? ", " : "");
    }
    cout << "]";
}