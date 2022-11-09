#include <iostream>
#include <array>

// STL Array is just a thin wrapper (with zero overhead) over the built in array

using namespace std;

int main()
{
    array<int, 5> foo{10, 30, 20, 40, -10};

    // Accessing elements
    cout << "foo[1]: " << foo[1] << '\n';
    cout << "foo[4]: " << foo.at(4) << '\n';

    // Size
    int fooSize = foo.size();
    cout << "Size of foo: " << fooSize << '\n';

    // Printing all elements
    for (int i : foo)
    {
        cout << i << ' ';
    }
    cout << endl;

    // Check if empty
    bool isEmpty = foo.empty();
    cout << "Is foo empty? " << isEmpty << '\n';

    // Get elements at ends
    cout << "foo[0]: " << foo.front() << '\n';
    cout << "foo[4]: " << foo.back() << '\n';

    return 0;
}