#include <iostream>
#include <string>
using std::cout;
using std::string;

// I stands for interface. Abstract Classes are a way to implement Interfaces in CPP.
// In an interface all methods are pure virtual,
// In an abstract class some methods may be defined.
// Both are implemented using abstract classes in Cpp.
class IEmployee
{
    // Syntax to declare pure virtual functions.
    // These pure virtual fns must be defined in derived classes. If not then even those become abstract.
    virtual void askForPromotion() = 0;
};

class Employee : public IEmployee // Public inheritance
{
private: // It is private by default so not needed, but written for readability
    int uid;
    string name;
    string company;
    int age;

public:
    Employee()
    {
        this->name = "";
        this->company = "";
        this->age = -1;
    }

    // Constructor overloading
    Employee(string name, string company, int age)
    {
        this->name = name;
        this->company = company;
        this->age = age;
    }

    void giveIntro()
    {
        cout << "\nHello, my name is " << name;
        cout << "\nI work in " << company;
        cout << "\nI'm " << age << " years old.";
    }

    // Getters and Setters - Gives more control over class attributes
    void setName(string name)
    {
        // Regex expression to check if name is valid, if not throw error
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void setAge(int age)
    {
        if (age >= 18)
            this->age = age;
    }

    void askForPromotion()
    {
        // Complex Promotion deciding logic
        cout << '\n';
        if (age >= 20 && age < 45)
            cout << name << " got promoted";
        else
            cout << name << " , sorry. No promotion for you";
    }
};

int main()
{
    Employee e1("Dhroov", "Google", 20);
    cout << "Printing info about employee " << e1.getName() << ":-";
    // cout << e1.name // Error
    e1.giveIntro();
    e1.askForPromotion();
    cout << '\n';

    Employee e2;
    e2.setName("Gojo");
    e2.setAge(46);
    e2.askForPromotion();
    e2.giveIntro();
}