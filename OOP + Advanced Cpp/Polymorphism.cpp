#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void printSound()
    {
        cout << "Animal Sound not yet registered!\n";
    }
};

class Lion : public Animal
{
public:
    void printSound()
    {
        cout << "ROARRRRR!\n";
    }
};

class Cat : public Animal
{
public:
    void printSound()
    {
        cout << "Meow Meow\n";
    }
};

int main()
{
    Animal *a;
    Animal a1;
    Lion l1;
    Cat c1;

    a = &a1;
    a->printSound();

    a = &l1;
    a->printSound();

    a = &c1;
    a->printSound();
    return 0;
}