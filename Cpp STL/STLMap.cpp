#include <iostream>
#include <map>
#include <unordered_map> // For unordered_map
#include <utility>       // For pair
#include <string>

// STL Map stores data as key:value pairs
// STL Map stores keys in sorted order
// STL Map is implemented using Red-Black Tree or Balanced Tree
// STL Unordered_Map is implemented using HashTable
// STL Unordered_Map stores keys in random order
// Unordered_Map is faster than Map
// Code and methods for Unordered_Map are the same as Map, just the time complexities are different.
using namespace std;

void printMap(const map<int, string> &m);

int main()
{
    map<int, string> m;

    // Inserting key:value pairs
    m[1] = "One";
    m[10] = "Ten";
    m[5] = "Five";
    m.insert({2, "Two"});

    // Printing map data
    printMap(m);

    // Look for a particular key
    cout << "Is 10 present in the Map? " << m.count(10) << '\n';
    cout << "Is 200 present in the Map? " << m.count(200) << '\n';

    // Find the value for a corresponding key
    // Method 1 - .at() - IMP: This returns an exception if the key is not present in the map
    cout << "Value of key '10' is: " << m.at(10) << '\n';
    // Method 2 - .find() - Returns an iterator
    map<int, string>::iterator it = m.find(10);
    if (it != m.end())
    {
        cout << "Value of key '10' is: " << (*it).second << '\n';
    }
    else
    {
        cout << "Key '10' is not present in the map" << '\n';
    }

    // find() with an invalid key
    map<int, string>::iterator it2 = m.find(-10);
    if (it2 != m.end())
    {
        cout << "Value of key '-10' is: " << (*it2).second << '\n';
    }
    else
    {
        cout << "Key '-10' is not present in the map" << '\n';
    }

    // Deleting a key:value pair
    cout << "\nBefore Erase:- \n";
    printMap(m);
    m.erase(10);
    cout << "Erased key 10 \n\n";
    cout << "After Erase:- \n";
    printMap(m);
    return 0;
}
void printMap(const map<int, string> &m)
{
    cout << "Printing map data: \n";
    for (pair p : m)
    {
        cout << p.first << ": " << p.second << '\n';
    }
    cout << '\n';
}
