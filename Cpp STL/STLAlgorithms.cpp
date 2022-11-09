#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(12);
    v.push_back(17);
    v.push_back(20);

    // Printing elements of vector v
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << '\n';

    // Binary Search
    cout << "Is 15 present in v? " << binary_search(v.begin(), v.end(), 15) << '\n';
    cout << "Is 17 present in v? " << binary_search(v.begin(), v.end(), 17) << '\n';
}