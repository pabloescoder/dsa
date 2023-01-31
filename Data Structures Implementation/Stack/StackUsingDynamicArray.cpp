#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int topIdx;
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
    Stack()
    {
        arr = new int[10];
        maxSize = 10;
        topIdx = -1;
    }
    Stack(int initialSize)
    {
        arr = new int[initialSize];
        maxSize = initialSize;
    }

    void push(int data)
    {
        if (topIdx == maxSize - 1)
            increaseSize();

        arr[++topIdx] = data;
    }

    void pop()
    {
        if (topIdx == -1)
        {
            cout << "Error: Nothing to pop. Stack is empty\n";
            return;
        }
        topIdx--;
    }

    int top()
    {
        if (topIdx == -1)
        {
            return INT_MIN;
        }
        return arr[topIdx];
    }

    bool isEmpty()
    {
        return (topIdx == -1);
    }

    ~Stack()
    {
        delete[] arr;
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