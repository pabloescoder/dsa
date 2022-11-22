// https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
// Related (but not same) question: https://practice.geeksforgeeks.org/problems/count-element-occurences/1
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility> // For pair

// Given an array of size n and an integer k, find all elements in the array that appear more than n/k times.
using namespace std;

// Approach 1 - Using unordered_set
// Store the count of how many times each elements occurs (frequency count)
// Add all the elements that occur more than n/k times to the final vector
// Return that vector
// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> findOccurencesUsingUnorderedSet(int arr[], int n, int k)
{
    // k must be greater than 1 to get some output
    if (k < 2)
        return;

    int threshold{n / k};
    unordered_map<int, int> freqMap;
    vector<int> elements;
    for (int i = 0; i < n; i++)
    {
        freqMap[arr[i]]++;
    }

    for (auto entry : freqMap)
    {
        if (entry.second > threshold)
        {
            elements.push_back(entry.first);
        }
    }
    return elements;
}

// Approach 2 - Modified Moore's Voting Algo
// Ref: https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/#:~:text=Moore%E2%80%99s%20Voting%20Algorithm%3A
// Has lesser space complexity than Approach 1, but greater time complexity than Approach 1
// Follow the steps below to solve the problem:
// Create a temporary array of size (k – 1) to store elements and their counts (The output elements are going to be among these k-1 elements).
// Traverse through the input array and update temp[] (add/remove an element or increase/decrease count) for every traversed element.
// The array temp[] stores potential (k-1) candidates at every step.
// Iterate through final(k - 1) potential candidates(stored in temp[]).
// For every element, check if it actually has counted of more than n / k.
// Time Complexity: O(N * K), Checking for each element of the array(size N) in the candidate array of size K
// Space Complexity: O(K), Space required to store the candidates.

vector<int> findOccurrencesUsingMooresVotingAlgo(int arr[], int n, int k)
{
    // k must be greater than 1 to get some output
    if (k < 2)
        return;

    // A structure to store an element and its current count
    struct elementCount
    {
        int element;
        int count{0}; // Initialize count of all elements to 0
    };

    struct elementCount *temp = new elementCount[k - 1]; // Creating an array of elementCount objects
    vector<int> elements;                                // Vector to store final solution

    // Step 1: Process all elements of input array
    for (int i = 0; i < n; i++)
    {
        int j;

        // If arr[i] is already present in the element count array, then increment its count
        for (j = 0; j < k - 1; j++)
        {
            if (arr[i] == temp[j].element)
            {
                temp[j].count += 1;
                break;
            }
        }

        // If arr[i] is not present in temp[]
        if (j == k - 1)
        {
            int l;

            // If there is a position available in temp[],
            // then place arr[i] in the first available position and set count as 1
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].count == 0)
                {
                    temp[l].element = arr[i];
                    temp[l].count = 1;
                    break;
                }
            }

            // If all the position in the temp[] are filled,
            // then decrease count of every element by 1
            if (l == k - 1)
            {
                for (l = 0; l < k - 1; l++)
                {
                    temp[l].count -= 1;
                }
            }
        }
    }

    // Step 2: Check actual counts of potential candidates in temp[]
    for (int i = 0; i < k - 1; i++)
    {
        // Calculate actual count of elements
        int ac{0}; // Actual count
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == temp[i].element)
            {
                ac++;
            }
        }

        // If actual count is more than n/k, then add it to the elements vector
        if (ac > (n / k))
        {
            elements.push_back(temp[i].element);
        }
    }
    delete[] temp; // Free dynamically allocated memory
    return elements;
}

int main()
{
    int arr[]{3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k{4};
    vector<int> elements{findOccurencesUsingUnorderedSet(arr, n, k)};       // [2 , 3]
    vector<int> elements2{findOccurrencesUsingMooresVotingAlgo(arr, n, k)}; // [3 , 2]
    for (int i : elements2)
    {
        cout << i << ' ';
    }
    cout << '\n';
}