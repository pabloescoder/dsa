#include <iostream>
#include <set>
#include <unordered_set> // For unordered_set

// STL Set stores only unique elements. Implemented using BST.
// Since STL Set uses BST, elements are stored in sorted order.
// Unordered_Set returns elements in random order (not sorted).
// Unordered_Set is faster than Set
// Code and methods for Unordered_Set are the same as Set, just the time complexities are different.
using namespace std;
void printSet(const set<int> s);

int main()
{
    set<int> s;

    // Inserting element - Complexity is O(log n) for set (BST)
    //                   - Complexity is O(1) for unordered_set (hashing)
    // Set stores unique elements in sorted order.
    s.insert(10);
    s.insert(-20);
    s.insert(-20);
    s.insert(-20);
    s.insert(20);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    printSet(s);

    // Removing elements
    // s.erase(s.begin()); // Remove first element
    set<int>::iterator it = s.begin();
    advance(it, 3);
    s.erase(s.begin(), it); // Remove first 3 elements from set
    cout << "Set after removing first 3 elements: " << '\n';
    printSet(s);

    s.insert(40);
    s.insert(-20);
    s.insert(60);
    cout << "Set after adding 3 new elements: " << '\n';
    printSet(s);

    // Check if an element is present in the set
    cout << "Is 40 present in the set? " << s.count(40) << '\n';
    cout << "Is 5 present in the set? " << s.count(5) << '\n';

    // Check if element is present using find method - Returns iterator
    cout << "Is 40 present in the set? " << (s.find(40) != s.end()) << '\n';
    cout << "Is 5 present in the set? " << (s.find(5) != s.end()) << '\n';
    cout << "Is 60 present in the set? " << (s.find(60) != s.end()) << '\n';
    return 0;
}

void printSet(const set<int> s)
{
    // Printing set elements
    for (int i : s)
    {
        cout << i << ' ';
    }
    cout << '\n';
}