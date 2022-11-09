#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<string> s;

    // Inserting elements
    s.push("Apple");
    s.push("Banana");
    s.push("Carrot");

    // Accessing the element at the top of the stack
    cout << "Top -> " << s.top() << '\n';

    // Removing elements from top (Popping off the stack)
    s.pop();
    cout << "After pop operation" << '\n';
    cout << "Top -> " << s.top() << '\n';

    // Size of stack + Is empty
    cout << "Size of stack: " << s.size() << '\n';
    cout << "Is stack s empty? " << s.empty() << '\n';

    return 0;
}