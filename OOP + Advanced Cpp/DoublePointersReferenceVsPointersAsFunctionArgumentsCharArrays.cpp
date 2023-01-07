#include <iostream>
using namespace std;

// Pointer as function argument
int multiplyP(int *num1, int *num2)
{
    // num1 as well as num2 can be null/0 since we have used pointers
    // num1 and num2 can be reassigned as well since we are using pointer arguments
    // num1 and num2 need to be dereferenced to get their values
    return *num1 * *num2;
}

// Reference as function argument
int multiplyR(const int &num1, const int &num2)
{
    // Not compulsory but we generally use const while taking arguments as references
    // num1 and num2 cannot be null/0 as they are refereces
    // num1 and num2 cannot be reassigned
    // num1 and num2 can be used as is without dereferencing
    return num1 * num2;
}

int main()
{
    // Pointer to pointer --- Double Pointer --- Triple Pointer
    int a = 20;
    cout << a << endl;
    int *ptr = &a;
    int **dbl_ptr = &ptr;
    int ***tpl_ptr = &dbl_ptr;
    **dbl_ptr = 200;
    cout << a << "\n\n";
    cout << "a = " << a << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "**dbl_ptr = " << **dbl_ptr << endl;
    cout << "***tpl_ptr = " << ***tpl_ptr << "\n\n";
    cout << "&a = " << &a << endl;
    cout << "ptr = " << ptr << endl;
    cout << "*dbl_ptr = " << *dbl_ptr << endl;
    cout << "**tpl_ptr = " << **tpl_ptr << "\n\n";
    cout << "&ptr = " << &ptr << endl;
    cout << "dbl_ptr = " << dbl_ptr << endl;
    cout << "*tpl_ptr = " << *tpl_ptr << "\n\n";
    cout << "&dbl_ptr = " << &dbl_ptr << endl;
    cout << "tpl_ptr = " << tpl_ptr << "\n\n";
    cout << "&tpl_ptr = " << &tpl_ptr << "\n\n";

    // Pointer as function argument vs Reference as function argument
    int a1 = 5, a2 = 5;
    int b1 = 10, b2 = 10;
    cout << multiplyP(&a1, &b1) << '\n'; // Pointer arguments, we need to use the address operator & explicitly
    cout << multiplyR(a2, b2) << '\n';   // Reference arguments, no need to explicitly pass the reference

    // Pointers vs References.
    int x = 20;
    int y = 10;
    int *pointer;
    cout << "\nint *pointer" << '\n';
    cout << "-> pointer = " << pointer << '\n';
    pointer = &x;
    cout << "\npointer = &x" << '\n';
    cout << "-> pointer = " << pointer << '\n';
    cout << "-> *pointer = " << *pointer << '\n';
    pointer = &y;
    cout << "\npointer = &y" << '\n';
    cout << "-> pointer = " << pointer << '\n';
    cout << "-> *pointer = " << *pointer << '\n';
    cout << "-> x = " << x << '\n';
    cout << "-> y = " << y << "\n\n";

    // int &reference; // Not allowed. Reference must be initialized. Once assigned cannot be changed.
    int &reference = x;
    cout << "int &reference = x" << '\n';
    cout << "-> &reference = " << &reference << '\n';
    cout << "-> reference = " << reference << '\n';
    reference = y; // Value of reference doesn't change, instead value of x changes b/c reference was of x
    cout << "\nreference = y" << '\n';
    cout << "-> &reference = " << &reference << '\n';
    cout << "-> reference = " << reference << '\n';
    cout << "-> x = " << x << '\n';
    cout << "-> y = " << y << "\n\n";

    // Char Arrays and Pointers
    char abc[] = "Hello";
    char *abc_ptr = abc;
    // Char pointers print all values until it gets a '\0' whereas regular pointers print the address they are pointing to when we print them
    cout << "abc_ptr = " << abc_ptr << '\n';
    while (*abc_ptr != '\0')
    {
        cout << "*abc_ptr = " << *abc_ptr << '\n';
        abc_ptr += 1;
    }
}