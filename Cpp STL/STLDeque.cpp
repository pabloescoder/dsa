#include <iostream>
#include <deque>

// Deque works similar to a list but uses multiple arrays to store data,
// elements inside the array are stored contiguously BUT 2 arrays may not be contiguous.
// Whereas list uses a doubly linked list to store data.

using namespace std;

void printDeque(const deque<int> &d);

int main()
{
    deque<int> d;

    // Inserting at the end
    d.push_back(10);
    d.push_back(20);

    // Inserting at the front
    d.push_front(30);
    d.push_front(40);
    printDeque(d);

    // Removing elements from the end
    d.pop_back();

    // Removing elements from the front
    d.pop_front();
    printDeque(d);

    cout << "Element at index 1: " << d.at(1) << '\n'; // Direct access
    cout << "Size of deque d: " << d.size() << '\n';   // Check length of deque
    cout << "Is d empty? " << d.empty() << '\n';       // Check if empty
    cout << "Front: " << d.front() << '\n';            // Get element at the front
    cout << "Back: " << d.back() << '\n';              // Get element at the back

    // Clear Deque : Removes all elements, makes size 0
    d.clear();
    cout << "Size after clearing deque: " << d.size() << '\n';

    // Insert multiple elements at once
    d.insert(d.end(), {10, 20, 30, 40});
    printDeque(d);

    // Erase (Remove a specific number of elements)
    d.erase(d.begin(), d.begin() + 2); // Will remove 2 elements from the beginning
    // We can also use d.end() to get the iterator from the end.
    printDeque(d);

    return 0;
}

void printDeque(const deque<int> &d)
{
    // Printing elements
    for (int i : d)
    {
        cout << i << ' ';
    }
    cout << '\n';
}