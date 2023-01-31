#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int frontIdx;
    int rearIdx;
    int maxSize;
    void increaseSize()
    {
        int *newArr = new int[maxSize * 2];
        for (int i = 0; i < maxSize; i++)
        {
            newArr[i] = arr[i];
        }

        int *prevArr = arr;
        arr = newArr;
        maxSize *= 2;
        delete[] prevArr;
    }

public:
    Queue()
    {
        arr = new int[10];
        frontIdx = -1;
        rearIdx = -1;
        maxSize = 10;
    }
    Queue(int initialSize)
    {
        arr = new int[initialSize];
        frontIdx = -1;
        rearIdx = -1;
        maxSize = initialSize;
    }

    bool isEmpty()
    {
        return (rearIdx == -1 && frontIdx == -1);
    }

    void enqueue(int data)
    {
        if ((rearIdx + 1) % maxSize == frontIdx) // If queue is full
        {
            increaseSize();
            rearIdx = (rearIdx + 1) % maxSize;
        }
        else if (isEmpty())
        {
            frontIdx = 0;
            rearIdx = 0;
        }
        else
        {
            rearIdx = (rearIdx + 1) % maxSize;
        }
        arr[rearIdx] = data;
    }

    void dequeue()
    {
        if (frontIdx == -1 && rearIdx == -1)
        {
            cout << "Error: Queue is empty. Nothing to dequeue.\n";
            return;
        }
        else if (frontIdx == rearIdx)
        {
            frontIdx = -1;
            rearIdx = -1;
            return;
        }
        frontIdx = (frontIdx + 1) % maxSize;
    }

    int front()
    {
        if (frontIdx == -1 && rearIdx == -1)
        {
            return INT_MIN;
        }
        return arr[frontIdx];
    }

    ~Queue()
    {
        delete[] arr;
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