#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev = nullptr;
    Node *next = nullptr;

    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertBegin(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!tail)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAt(int index, int data)
    {
        Node *newNode = new Node(data);
        if (!head && index != 0)
        {
            cout << "Error! Index out of bounds.\n";
            return;
        }
        else if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        int currIdx = 0;
        Node *temp = head;
        while (temp && currIdx != index - 1)
        {
            temp = temp->next;
            currIdx++;
        }

        if (currIdx != index - 1)
        {
            cout << "Error! Index out of bounds.\n";
        }
        else
        {
            newNode->next = temp->next;
            if (temp->next)
                temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;

            if (!newNode->next)
                tail = newNode;
        }
    }

    void deleteBegin()
    {
        if (!head)
        {
            cout << "Linked List is empty. Nothing to delete.\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void deleteEnd()
    {
        if (!tail)
        {
            cout << "Linked List is empty. Nothing to delete.\n";
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }

    void deleteAt(int index)
    {
        if (!head)
        {
            cout << "Linked List is empty. Nothing to delete.\n";
            return;
        }
        else if (!head->next && index == 0)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        int currIdx = 0;
        Node *temp = head;
        while (temp && currIdx != index)
        {
            temp = temp->next;
            currIdx++;
        }

        if (!temp)
        {
            cout << "Error. Given index is greater than the length of the Linked List!\n";
        }
        else
        {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            delete temp;
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
                cout << temp->data << " <-> ";
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