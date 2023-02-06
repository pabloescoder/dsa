#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Coordinate
{
public:
    int x;
    int y;

    Coordinate()
    {
        this->x = 0;
        this->y = 0;
    }

    Coordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void print()
    {
        cout << "(" << x << ", " << y << ")";
    }
};

void printVec(const vector<int> &v);
void printArr(int *arr, int size);
void printPoints(Coordinate *pointsArr, int size);

bool comparePoints(const Coordinate &c1, const Coordinate &c2) // Comparator
{
    if (c1.x != c2.x)
        return c1.x < c2.x;
    return c1.y < c2.y;
}

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(12);
    v.push_back(17);
    v.push_back(20);
    printVec(v);

    // Binary Search
    cout << "Is 15 present in v? " << binary_search(v.begin(), v.end(), 15) << '\n';
    cout << "Is 17 present in v? " << binary_search(v.begin(), v.end(), 17) << "\n\n";

    // Sorting - STL collections
    vector<int> v1 = {10, -20, 50, 0, 30, -40};
    cout << "Before: ";
    printVec(v1);
    sort(v1.begin(), v1.end()); // Sorting Vector using sort()
    cout << "After: ";
    printVec(v1);

    // Sorting - Arrays
    int arr[] = {10, -20, 50, 0, 30, -40};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before: ";
    printArr(arr, n);
    sort(arr, arr + n); // Sorting Array using sort()
    cout << "After: ";
    printArr(arr, n);
    cout << '\n';

    // Sorting - With User Defined Objects & Comparator
    Coordinate points[10];
    for (int i = 0; i < 10; i++)
        points[i] = Coordinate(rand() % 50 + 1, rand() % 20 + 1);

    cout << "Before:- ";
    printPoints(points, 10);
    sort(points, points + 10, comparePoints); // Sorting Array of user defined objects using sort() and passing a comparator
    cout << "After:- ";
    printPoints(points, 10);
}

void printVec(const vector<int> &v)
{
    for (int i : v)
        cout << i << " ";
    cout << '\n';
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

void printPoints(Coordinate *pointsArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        pointsArr[i].print();
        cout << ((i != size - 1) ? ", " : "");
    }
    cout << '\n';
}