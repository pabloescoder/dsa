#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    queue<string> q;

    // Adding elements at the end of queue (FIFO)
    q.push("First");
    q.push("Second");
    q.push("Third");

    // Accessing element at the front of the queue
    cout << "Front: " << q.front() << '\n';

    // Removing the element at the start of the queue
    q.pop();
    cout << "After pop (de-queue) operation \n";
    cout << "Front: " << q.front() << '\n';

    // Size of queue + Is empty
    cout << "Size of queue: " << q.size() << '\n';
    cout << "Is queue q empty? " << q.empty() << '\n';
}