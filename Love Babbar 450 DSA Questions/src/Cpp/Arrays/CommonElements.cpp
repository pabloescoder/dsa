// https://practice.geeksforgeeks.org/problems/common-elements1132/1
#include <iostream>
#include <vector>

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?
// Time Complexity: O(N1 + N2 + N3)
// Space Complexity: O(N1 + N2 + N3) // Since we are storing common elements in a vector
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> common;
    int aP{0}, bP{0}, cP{0};
    while (aP < n1 && bP < n2 && cP < n3)
    {
        if (A[aP] == B[bP] && B[bP] == C[cP])
        {
            if (common.empty() || common.back() != A[aP])
            {
                common.push_back(A[aP]);
            }
            aP++;
            bP++;
            cP++;
        }
        else if (A[aP] < B[bP])
        {
            aP++;
        }
        else if (B[bP] < C[cP])
        {
            bP++;
        }
        else
        {
            cP++;
        }
    }
    return common;
}

int main()
{
    int n1{94};
    int n2{32};
    int n3{63};
    int arr1[]{-95, -94, -94, -94, -90, -89, -85, -82, -81, -79, -74, -70, -70, -69, -68, -66, -65, -65, -63, -61, -59, -56, -53, -52, -51, -49, -44, -42, -36, -32, -30, -29, -23, -20, -19, -18, -17, -16, -16, -15, -12, -12, -10, -8, -3, 0, 0, 1, 2, 2, 4, 5, 8, 11, 14, 22, 23, 29, 31, 32, 33, 35, 35, 37, 37, 40, 43, 48, 50, 54, 55, 57, 59, 60, 60, 64, 66, 68, 69, 71, 73, 73, 73, 76, 77, 78, 79, 81, 84, 85, 86, 92, 93, 97};
    int arr2[]{-85, -74, -71, -66, -63, -54, -45, -36, -36, -34, -30, -29, -4, 6, 16, 16, 20, 20, 24, 28, 28, 28, 38, 50, 56, 56, 58, 59, 75, 76, 84, 92};
    int arr3[]{-99, -99, -95, -94, -86, -79, -72, -72, -69, -54, -54, -53, -50, -42, -41, -39, -36, -35, -34, -26, -19, -14, -14, -12, -12, -11, -11, -9, -9, -7, -7, -4, 5, 5, 6, 13, 17, 18, 23, 25, 27, 34, 37, 37, 38, 47, 48, 55, 60, 69, 69, 71, 72, 72, 73, 80, 81, 82, 90, 92, 97, 98, 99};
    vector<int> common = commonElements(arr1, arr2, arr3, n1, n2, n3); // -36 92
    for (int i : common)
    {
        cout << i << " ";
    }
    return 0;
}