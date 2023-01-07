// Program to find the number of objects of a class A created throughout the program.
// Number of objects created = Obj created statically (Stack) + Obj created dynamically (Heap)

#include <iostream>
using namespace std;

class A
{
public:
    static int numObj; // Static variable to store number of objects. All objects share this variable

    // Constructor to increment num of objects when a new one is created
    A()
    {
        numObj += 1;
    }

    // Destructor to decrement num of objects when a current obj is deleted
    ~A()
    {
        numObj -= 1;
    }
};

int A::numObj = 0; // Initializes static variable with 0

int main()
{
    // Objects created statically - Stored in stack
    A a, b, c;
    A d, e;

    // Objects created dynamically - Stored in heap

    // Malloc only allocates space and does NOT call constructor
    // A *x = (A *)malloc(sizeof(A));

    // The keyword new allocates space as well as calls constructor. Prefer using this.
    A *x = new A;
    A *y = new A;

    // Free only deallocates space but does NOT call destructor
    // free(x);

    // The keyword delete deallocates space as well as calls Destructor. Prefer using this.
    delete (x);

    cout << "Total objects of A at this point = " << A::numObj; // 6
    return 0;
}