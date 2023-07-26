#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{
    Node *frontP;
    Node *rearP;

public:
    Queue()
    {
        frontP = nullptr;
        rearP = nullptr;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (frontP == nullptr && rearP == nullptr)
        {
            frontP = newNode;
            rearP = newNode;
            return;
        }
        rearP->next = newNode;
        rearP = newNode;
    }

    void dequeue()
    {
        if (frontP == nullptr && rearP == nullptr)
        {
            cout << "Error: Queue is empty. Nothing to dequeue.\n";
            return;
        }
        if (frontP == rearP)
        {
            delete frontP;
            frontP = nullptr;
            rearP = nullptr;
            return;
        }
        Node *temp = frontP;
        frontP = frontP->next;
        delete temp;
    }

    int front()
    {
        if (frontP == nullptr && rearP == nullptr)
        {
            return INT_MIN;
        }
        return frontP->data;
    }

    bool isEmpty()
    {
        return (frontP == nullptr && rearP == nullptr);
    }
};

int main()
{
    Queue q1;
    q1.dequeue();
    cout << boolalpha;
    cout << "q1.isEmpty() = " << q1.isEmpty() << '\n';
    cout << "q1.front() = " << q1.front() << '\n';
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "q1.enqueue(10); q1.enqueue(20); q1.enqueue(30);\n";
    cout << "q1.isEmpty() = " << q1.isEmpty() << '\n';
    cout << "q1.front() = " << q1.front() << '\n';
    q1.dequeue();
    q1.dequeue();
    cout << "q1.dequeue(); q1.dequeue();\n";
    cout << "q1.front() = " << q1.front() << '\n';
}