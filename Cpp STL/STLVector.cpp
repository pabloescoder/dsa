#include <iostream>
#include <vector>

// STL Vector is a Dynamic Array. Just like ArrayList in Java.

using namespace std;

// Pass by reference, passing it as const because we do not want to modify the vector.
void printVector(const vector<int> &v);

int main()
{
    vector<int> v;

    // By default all elements are initialized with 0, capacity is 0, size is 0.
    // To initialize elements with a something other than 0, we can pass an additional argument
    vector<int> v5(5, 10); // Initialize with size 5, and each element will be 10.
    cout << "Printing elements of vector v5:- " << '\n';
    printVector(v5);

    // Initializing a vector with another vector
    vector<int> newV5{v5};
    cout << "Printing elements of vector newV5:- " << '\n';
    printVector(newV5);

    // Inserting elements at the end (of the dynamic array)
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // Removing elements from the end
    v.pop_back(); // Does not return anything.

    cout << "Printing elements of vector v:- " << '\n';
    printVector(v);

    // Capacity is the total number of elements that can be stored in the vector
    // Capacity is changed dynamically as we keep on adding new elements.
    // We generally won't require capacity in our programs, instead what we need is Size
    // Size is the total number of elements currently stored in the vector.
    cout << "Capacity of v (Not useful generally): " << v.capacity() << '\n';
    cout << "Size of v: " << v.size() << "\n\n";

    // Accessing elements
    cout << "v[2]: " << v[2] << '\n';
    cout << "v[1]: " << v.at(1) << '\n';
    cout << "v[0]: " << v.front() << '\n';
    cout << "v[2]: " << v.back() << "\n\n";

    // Clear - Size becomes 0 and elements get deleted but capacity is unchanged
    v.clear();
    cout << "Size after clearing: " << v.size() << '\n';
    cout << "Capacity after clearing: " << v.capacity() << "\n\n";
    return 0;
}

void printVector(const vector<int> &v)
{
    // Printing elements
    for (int i : v)
    {
        cout << i << ' ';
    }
    cout << "\n\n";
}