#include <iostream>
#include <queue>

// STL Priority_Queue works like a Max Heap by default. It can also be used as a Min Heap.
using namespace std;
void printMaxHeap(priority_queue<int> pq);
void printMinHeap(priority_queue<int, vector<int>, greater<int>> pq);

int main()
{
    // By default priority_queue is a max heap
    priority_queue<int> maxi;

    // For min heap the structure is:-
    priority_queue<int, vector<int>, greater<int>> mini;

    // Insert elements
    maxi.push(10);
    maxi.push(-10);
    maxi.push(40);
    maxi.push(-20);

    mini.push(10);
    mini.push(-10);
    mini.push(40);
    mini.push(-20);

    // Get maximum element in max heap
    cout << "Maximum element in max heap: " << maxi.top() << '\n';

    // Get minimum element in min heap
    cout << "Minimum element in min heap: " << mini.top() << '\n';

    // Print max heap
    printMaxHeap(maxi);
    // Print min heap
    printMinHeap(mini);

    // Remove element at the top of the heap
    maxi.pop();
    cout << "After popping one element from maxi, element at top of heap is: " << maxi.top() << '\n';

    return 0;
}

// Not passing by reference because we dont want to modify orignal priority_queue
void printMaxHeap(priority_queue<int> pq)
{
    cout << "Printing max heap elements: \n";
    int size = pq.size();
    for (int i = 0; i < size; i++)
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}

void printMinHeap(priority_queue<int, vector<int>, greater<int>> pq)
{
    cout << "Printing min heap elements: \n";
    int size = pq.size();
    for (int i = 0; i < size; i++)
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
};
