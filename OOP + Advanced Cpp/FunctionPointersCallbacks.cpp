#include <iostream>
#include <cmath> // For abs()
#include <string>
using namespace std;

int sum5(int num)
{
    return num + 5;
}

void printGreeting(string name)
{
    cout << "Hello " << name << "!\n";
}

// Takes a callback function as argument of return type void that accepts one string
void callPrintGreeting(void (*print)(string), string name)
{
    print(name); // Calling the callback function
}

// Returns -ve if first < second, +ve if first > second, 0 otherwise
int compareAscending(int first, int second)
{
    return first - second;
}

int compareDescending(int first, int second)
{
    return second - first;
}

// Returns -ve if |first| < |second|, +ve if |first| > |second|, 0 otherwise
int compareAbsAscending(int first, int second)
{
    return abs(first) - abs(second);
}

// Takes a callback comparator that determines whether to sort in ascending or descending
void bubbleSort(int arr[], int n, int (*comparator)(int, int))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swaps if comparator returns +ve value
            if (comparator(arr[j], arr[j + 1]) > 0)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ((i == n - 1) ? "" : ", ");
    }
    cout << " ]\n";
}

int main()
{
    // Syntax of creating a function pointer
    // <Return_Type> (*PTR) (arg1_type, arg2_type, ... argn_type) = <Function_Name>;
    int (*p)(int) = sum5;
    // Calling the function sum5 using its function pointer p
    cout << p(20) << '\n'; // 25

    int c = p(100);
    cout << c << '\n'; // 105

    // Callbacks
    void (*callUser)(string) = printGreeting;
    callPrintGreeting(callUser, "Dhroov"); // Hello Dhroov!
    cout << '\n';

    int arr1[] = {-2, 200, 10, -20, 60, 35, -25};
    int arr2[] = {-2, 200, 10, -20, 60, 35, -25};
    int arr3[] = {-2, 200, 10, -20, 60, 35, -25};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Function pointers to our comparator callback functions
    int (*compareAsc)(int, int) = compareAscending;
    int (*compareDesc)(int, int) = compareDescending;
    int (*compareAbsAsc)(int, int) = compareAbsAscending;

    cout << "Before Sorting: ";
    printArr(arr1, n);

    bubbleSort(arr1, n, compareAsc);
    cout << "Ascending: ";
    printArr(arr1, n);

    bubbleSort(arr2, n, compareDesc);
    cout << "Descending: ";
    printArr(arr2, n);

    bubbleSort(arr3, n, compareAbsAsc);
    cout << "Ascending order of magnitude (by absolute value): ";
    printArr(arr3, n);

    return 0;
}