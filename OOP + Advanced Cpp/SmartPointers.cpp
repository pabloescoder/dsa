#include <iostream>
#include <memory>
using namespace std;

class Entity
{
public:
    Entity()
    {
        cout << "Entity constructor called!" << endl;
    }
    ~Entity()
    {
        cout << "Entity destructor called!" << endl;
    }
};

int main()
{
    // Smart pointers help you to make pointers without using the new and delete keywords
    // Ie. They are a wrapper over using new and delete manually, internally they still use that
    // But the advantage is that now we don't have to manually allocate and deallocate memory.
    // The smart pointers themselves will handle all the memory management, we can focus on using the pointers.
    // NOTE: Smart pointers automate memory management & prevent accidental memory leaks.

    cout << "Unique Pointer" << endl;
    // Unique pointers are scoped poiners
    // That is, once the pointer goes out of scope, it will automatically be deleted and memory will be freed.
    // As its name suggests, unique pointers cannot be reassigned using copy assignment
    // Ie. They can't be copied.
    // We can make a scope manually using {}
    {
        unique_ptr<Entity> eUniquePtr = make_unique<Entity>();
        cout << "Inside the scope, eUniquePtr still pointing to a valid object in memory...\n";
    }
    cout << "Outside eUniquePtr scope.\n";

    cout << "\nShared Pointer\n";
    // A shared pointer is used when you want to share the pointer with multiple pointer variables
    // In unique pointer, the pointer deallocates space for the object it was pointing to once it is out of scope
    // In a shared pointer, the pointer will deallocate space for the object when ALL pointers go out of scope.
    // The way it does this is by maintaining a reference count.
    // For every shared pointer pointing to the object, the reference count is incremented by one.
    // For every shared pointer going out of scope the reference count is decremented by 1.
    // The object is deallocated from memory and space is freed when the reference count is 0.
    {
        shared_ptr<Entity> outerSharedPtr;
        {
            shared_ptr<Entity> innerSharedPtr = make_shared<Entity>();
            outerSharedPtr = innerSharedPtr;
            cout << "Inside inner scope, shared ptr is alive, ";
            cout << "Reference count = " << outerSharedPtr.use_count() << endl;
        }
        cout << "Inside outer scope, shared ptr is still alive, ";
        cout << "Reference count = " << outerSharedPtr.use_count() << endl;
    }
    cout << "Outside outer scope. Reference count is now 0";

    // Weak pointer
    cout << "\n\nWeak Pointer\n";
    // Weak pointer is just like shared pointer, it can be used to store the value of a shared pointer
    // However one big difference is that weak pointers do not increase reference count
    // So they are used when we don't want actual ownership of the object, rather
    // We just want a temporary pointer to it.
    // NOTE: Weak pointers do NOT increase reference count.
    weak_ptr<Entity> weak;
    {
        shared_ptr<Entity> shared = make_shared<Entity>();
        weak = shared;
        cout << "Inside shared ptr scope, weak ptr is -> " << (weak.expired() ? "Dead" : "Alive") << endl;
    }
    cout << "Outside shared ptr scope, weak ptr is -> " << (weak.expired() ? "Dead" : "Alive") << endl;
}