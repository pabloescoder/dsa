#include <iostream>
#include <list>

// STL List is implemented using a Doubly Linked List.
using namespace std;

void printList(const list<int> &l);

int main()
{
    list<int> l;

    // Inserting elements at front and back.
    l.push_front(10);
    l.push_back(20);
    l.push_front(30);
    l.push_back(40);
    printList(l);

    // Removing elements from both ends.
    l.pop_back();
    l.pop_front();
    printList(l);

    // Accessing elements - Direct access not allowed. O(n) access complexity.
    list<int>::iterator it = l.begin(); // Initialize list iterator and point it to the first entry
    advance(it, 1);                     // Make it point to the second element in the list
    cout << "Element at index 2 in list: " << *it << '\n';

    // Size of list
    cout << "Size: " << l.size() << '\n';

    return 0;
}

void printList(const list<int> &l)
{
    for (int i : l)
    {
        cout << i << ' ';
    }
    cout << '\n';
}