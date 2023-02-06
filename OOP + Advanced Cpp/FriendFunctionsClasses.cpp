#include <iostream>
using namespace std;

class Distance
{
    int distance;

public:
    Distance() : distance(20){};

    void printRemainingDistance()
    {
        cout << distance << '\n';
    }

    void walk()
    {
        distance -= 1;
        cout << "Walked 1 step\n";
    }

    // add5 is declared as a friend function.
    // A friend function can access all the variables and functions of the class
    // Even the private member variables and member methods.
    friend void add5(Distance &d);

    // class PrettyPrinter is declared as a friend class
    // That means PrettyPrinter will be able to access all variables and functions of Distance
    // Including all private member variables and member functions
    // Note that friendship is only granted, NOT taken.
    // So while PrettyPrinter can access all private members, Distance cannot access any private members of PrettyPrint
    // So, Distance cannot access mySecret
    friend class PrettyPrinter;
};

class PrettyPrinter
{
    int mySecret;

public:
    void prettyPrintRemainingDistance(Distance &d)
    {
        cout << "The remaining distance is: " << d.distance << '\n';
    }
};

// add5 has access to the private member variable 'distance'
// Because it is declared as a friend function of class Distance
void add5(Distance &d)
{
    cout << "add5 called\n";
    d.distance += 5;
}

int main()
{
    Distance d;
    PrettyPrinter p;
    d.printRemainingDistance();
    p.prettyPrintRemainingDistance(d);
    d.walk();
    p.prettyPrintRemainingDistance(d);
    add5(d);
    p.prettyPrintRemainingDistance(d);
}