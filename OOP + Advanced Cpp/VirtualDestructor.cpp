#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Constructor\n";
    }
    virtual ~Base()
    {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived Constructor\n";
    }

    ~Derived()
    {
        cout << "Derived Destructor\n";
    }
};

int main()
{
    // No problem, base pointer points to base object.
    Base *b = new Base(); // Base constructor called
    delete b;             // Base Destructor called
    // OP :-
    // Base Constructor
    // Base Destructor
    cout << endl;

    // No problem, derived pointer points to derived object.
    // Since the class Derived is derived from Base, Base constructor & destructor will also be called
    Derived *d = new Derived(); // Base Constructor then Derived Constructor called
    delete d;                   // Derived Destructor then Base Destructor called
    // OP :-
    // Base Constructor
    // Derived Constructor
    // Derived Destructor
    // Base Destructor
    cout << endl;

    // Here the problem arises. Object Pointer of type Base* points to a derived object (Derived)
    // Here, if we do not make the Base Destructor as virtual,
    // Then the compiler will NOT know that there is a Derived Destructor that must also be invoked.
    // Just like we used the keywork 'virtual' to perform function overriding,
    // We need to use it here in the base destructor to inform the compiler that there is also a derived destructor that must be invoked.
    // In case of destructors, the compiler doesn't override the destructors, instead it adds it to the list of destructors to be called.
    // Diff between using virtual => for functions (function is overriden) and for destructors (compiler adds it to the list of destructors to be invoked)
    // If we do not use virtual before the base destructor, then if we make an object of type Base* pointing to a Derived object,
    // Then it will not call the Derived Destructor. Rest everything is same.
    Base *b_d = new Derived(); // Base Constructor then Derived Constructor called.
    delete d;                  // Derived Destructor (If Base Destructor is virtual) then Base Destructor called.
    // Note: Some compilers will call the Derived Destructor even if the Base Destructor is not virtual. But this is a case of undefined behaviour.
    // So make sure to add the keyword 'virtual' to your destructor in the base class if it is being derived by another class.
    // OP :-
    // Base Constructor
    // Derived Constructor
    // Derived Destructor (If Base Destructor is NOT virtual then may or may not be invoked --- Undefined behaviour)
    // Base Destructor

    return 0;
}