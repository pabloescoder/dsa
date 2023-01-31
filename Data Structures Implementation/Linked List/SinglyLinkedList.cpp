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

class LinkedList
{
    Node *head;
    Node *tail; // Useful for inserting at the end in O(1)

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertBegin(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertEnd(int data)
    {
        Node *newNode = new Node(data);

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAt(int index, int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr && index != 0)
        {
            cout << "Error! Index out of bounds.\n";
            return;
        }
        else if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        int currIdx = 0;
        Node *temp = head;
        while (temp != nullptr && currIdx != index - 1)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Error! Index out of bounds.\n";
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;

            if (newNode->next == nullptr)
            {
                tail == newNode;
            }
        }
    }

    void deleteBegin()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty. Nothing to delete.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete temp;
    }

    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty. Nothing to delete.\n";
            return;
        }
        Node *end = head;
        Node *prev = head;
        while (end->next != nullptr)
        {
            prev = end;
            end = end->next;
        }
        prev->next = nullptr;
        tail = prev;
        delete end;
    }

    void deleteAt(int index)
    {
        if (head == nullptr)
        {
            cout << "Linked List is empty. Nothing to delete.\n";
            return;
        }

        int currIdx = 0;
        Node *curr = head;
        Node *prev = head;
        while (curr != nullptr && currIdx != index)
        {
            prev = curr;
            curr = curr->next;
            currIdx += 1;
        }

        if (curr == nullptr)
        {
            cout << "Error. Given index is greater than the length of the Linked List!\n";
        }
        else
        {
            prev->next = curr->next;
            if (curr == tail)
                tail = prev;
            delete curr;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->next == nullptr)
            {
                cout << temp->data;
            }
            else
            {
                cout << temp->data << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.display();
    ll.deleteBegin();
    ll.insertAt(0, 10);
    ll.display();
    ll.insertBegin(0);
    ll.display();
    ll.insertEnd(20);
    ll.insertEnd(30);
    ll.insertEnd(40);
    ll.display();
    ll.deleteBegin();
    ll.display();
    ll.deleteAt(2);
    ll.display();
    ll.deleteEnd();
    ll.display();
}