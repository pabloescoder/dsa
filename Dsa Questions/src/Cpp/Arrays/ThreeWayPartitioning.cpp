// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
#include <iostream>
#include <vector>
// Given an array of size n and a range [a, b].
// The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.
// Time Complexity: O(N)
// Space Complexity: O(1)
using namespace std;
void swap(int *a1, int *a2);
void printVector(vector<int> vec);

void threeWayPartition(vector<int> &array, int a, int b)
{
    int smallerP{0};
    int largerP{static_cast<int>(array.size()) - 1};
    int currP{0};
    while (currP <= largerP)
    {
        if (array[currP] > b)
        {
            swap(&array[largerP], &array[currP]);
            largerP--;
        }
        else if (array[currP] < a)
        {
            swap(&array[smallerP], &array[currP]);
            smallerP++;
            currP++;
        }
        else
        {
            currP++;
        }
    }
}

int main()
{
    vector<int> arr{76, 75, 8, 38, 96, 22, 30, 39, 45};
    cout << "Before: ";
    printVector(arr);
    int a = 44, b = 62;
    threeWayPartition(arr, a, b);
    cout << "After: ";
    printVector(arr);
    // Output:-
    // Before: 76 75 8 38 96 22 30 39 45
    // After: 39 8 38 30 22 45 96 75 76
}

void swap(int *a1, int *a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void printVector(vector<int> vec)
{
    for (int i : vec)
    {
        cout << i << ' ';
    }
    cout << '\n';
}