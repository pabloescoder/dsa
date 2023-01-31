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

class Stack
{
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (head == nullptr)
        {
            cout << "Error: Nothing to pop. Stack is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int top()
    {
        if (head == nullptr)
        {
            return INT_MIN;
        }
        return head->data;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }
};

int main()
{
    Stack s1;
    s1.pop();
    cout << boolalpha;
    cout << "s1.isEmpty() = " << s1.isEmpty() << '\n';
    cout << "s1.top() = " << s1.top() << '\n';
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "s1.push(10); s1.push(20); s1.push(30);\n";
    cout << "s1.isEmpty() = " << s1.isEmpty() << '\n';
    cout << "s1.top() = " << s1.top() << '\n';
    s1.pop();
    s1.pop();
    cout << "s1.pop(); s1.pop();\n";
    cout << "s1.top() = " << s1.top() << '\n';
}