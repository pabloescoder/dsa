// See StaticAttributesConstructorsDestructors.cpp first
// Program to find the number of objects of a class A stored dynamically (Heap) ONLY.
#include <iostream>
using namespace std;

class A
{
    // Constructors can't differentiate between statically created objects and dynamically created objects.
    // So we will use operator overloading and overload the new and delete operators.
    // new returns a void pointer and takes a size of dataType size_t as an argument.
    // delete takes a void pointer and returns nothing.
public:
    static int numDynamicObj;

    // Overload operator new
    void *operator new(size_t sz)
    {
        numDynamicObj += 1;
    }

    // Overload operator delete
    void operator delete(void *obj_ptr)
    {
        numDynamicObj -= 1;
    }
};

int A::numDynamicObj = 0;

int main()
{
    // Statically created objects --- Stack
    A a, b, c, d, e;

    // Dynamically created objects --- Heap
    A *x = new A;
    A *y = new A;
    A *z = new A;
    delete (x);
    cout << "Total dynamically created objects of A at this point = " << A::numDynamicObj; // 2
    return 0;
}