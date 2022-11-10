// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility> // For pair

// Given two arrays a[] and b[] of size n and m respectively.
// The task is to find union between these two arrays.
// Bonus: Write code to find the intersection b/w 2 arrays.

using namespace std;
void printVector(vector<int> v);
void printSet(unordered_set<int> s);

// UNION
// Approach 1 - Sort the arrays, then merge.
// Final union array is also sorted
// Time Complexity: O(NlogN + MlogM) <- sort() function
// Space Complexity: O(logN + logM) <- sort() function
vector<int> findUnionUsingVector(int arr1[], int n1, int arr2[], int n2)
{
    // Sort the two arrays if they are not sorted
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);
    vector<int> unionArr;
    int arr1P{0};
    int arr2P{0};
    while (arr1P < n1 && arr2P < n2)
    {
        if (arr1[arr1P] == arr2[arr2P])
        {
            if (count(unionArr.begin(), unionArr.end(), arr1[arr1P]) == 0)
            {
                unionArr.push_back(arr1[arr1P]);
            }
            arr1P++;
            arr2P++;
        }
        else if (arr1[arr1P] < arr2[arr2P])
        {
            if (count(unionArr.begin(), unionArr.end(), arr1[arr1P]) == 0)
            {
                unionArr.push_back(arr1[arr1P]);
            }
            arr1P++;
        }
        else
        {
            if (count(unionArr.begin(), unionArr.end(), arr2[arr2P]) == 0)
            {
                unionArr.push_back(arr2[arr2P]);
            }
            arr2P++;
        }
    }
    while (arr1P < n1)
    {
        unionArr.push_back(arr1[arr1P++]);
    }
    while (arr2P < n2)
    {
        unionArr.push_back(arr2[arr2P++]);
    }

    return unionArr;
}

// Approach 2 - Use unordered_set
// Final union array is not sorted since we are using unordered_set
// If sorted array is needed, sort it using the sort function or use set
// Time Complexity: O(N + M)  <- Assuming no collisions so insertion is O(1) always
// Space Complexity: O(N + M)
unordered_set<int> findUnionUsingSet(int arr1[], int n1, int arr2[], int n2)
{
    unordered_set<int> unionSet;
    for (int i = 0; i < n1; i++)
    {
        unionSet.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        unionSet.insert(arr2[i]);
    }

    return unionSet;
}

// INTERSECTION
// Approach 1 - Sort the arrays, then use modified merge method
// Final intersection array is also sorted.
// Time complexity: O(NlogN + MlogM)
// Space complexity: O(logN)
vector<int> findIntersectionUsingVector(int arr1[], int n1, int arr2[], int n2)
{
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);
    vector<int> interVec;
    int arr1P{0};
    int arr2P{0};
    while (arr1P < n1 && arr2P < n2)
    {
        if (arr1[arr1P] == arr2[arr2P])
        {
            if (!count(interVec.begin(), interVec.end(), arr1[arr1P]))
            {
                interVec.push_back(arr1[arr1P]);
            }
            arr1P++;
            arr2P++;
        }
        else if (arr1[arr1P] < arr2[arr2P])
        {
            arr1P++;
        }
        else
        {
            arr2P++;
        }
    }

    return interVec;
}

// Approach 2 - Use unordered_set
// Final intersection array is not sorted since we are using unordered_set
// If sorted array is needed, sort it using the sort function or use set
// Time Complexity: O(N + M)  <- Assuming no collisions so insertion is O(1) always
// Space Complexity: O(N + M)
unordered_set<int> findIntersectionUsingSet(int arr1[], int n1, int arr2[], int n2)
{
    int *smallerArr;
    int sLen;
    int *largerArr;
    int lLen;
    if (n1 < n2)
    {
        smallerArr = arr1;
        sLen = n1;
        largerArr = arr2;
        lLen = n2;
    }
    else
    {
        smallerArr = arr2;
        sLen = n2;
        largerArr = arr1;
        lLen = n1;
    }

    unordered_set<int> s;
    // Insert all elements of smallerArr in s
    for (int i = 0; i < sLen; i++)
    {
        s.insert(*(smallerArr + i));
    }

    unordered_set<int> intersectionSet;
    for (int i = 0; i < lLen; i++)
    {
        if (s.count(*(largerArr + i)) != 0)
        {
            intersectionSet.insert(*(largerArr + i));
        }
    }
    return intersectionSet;
}

int main()
{
    // Create arrays for testing the functions
    int arr1[]{85, 6, 1, 32, 54, 25, 85};
    const int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[]{85, 2, 85};
    const int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[n1];
    copy(arr1, arr1 + n1, arr3);
    int arr4[n2];
    copy(arr2, arr2 + n2, arr4);
    int arr5[n1];
    copy(arr1, arr1 + n1, arr5);
    int arr6[n2];
    copy(arr2, arr2 + n2, arr6);
    int arr7[n1];
    copy(arr1, arr1 + n1, arr7);
    int arr8[n2];
    copy(arr2, arr2 + n2, arr8);

    // Union
    vector<int> u1Vector{findUnionUsingVector(arr1, n1, arr2, n2)};
    printVector(u1Vector); // 1 2 6 25 32 54 85
    unordered_set<int> u2Set{findUnionUsingSet(arr3, n1, arr4, n2)};
    printSet(u2Set); // 85 2 54 25 32 6 1

    // Intersection
    vector<int> i1Vector{findIntersectionUsingVector(arr5, n1, arr6, n2)};
    printVector(i1Vector); // 85
    unordered_set<int> i2Set{findIntersectionUsingSet(arr7, n1, arr8, n2)};
    printSet(i2Set); // 85
    return 0;
}

void printVector(vector<int> v)
{
    for (int i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

void printSet(unordered_set<int> s)
{
    for (int i : s)
    {
        cout << i << ' ';
    }
    cout << '\n';
}