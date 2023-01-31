#include <iostream>
using namespace std;

void swap(int *, int *);

class MinHeap
{
    int *arr;
    int length;
    int maxLength;

    void heapifyDown(int i)
    {
        int l = (i * 2) + 1; // Left child index
        int r = (i * 2) + 2; // Right child index
        int min = i;
        if (l < length && arr[l] < arr[i])
        {
            min = l;
        }
        if (r < length && arr[r] < arr[min])
        {
            min = r;
        }
        if (min != i)
        {
            swap(arr[i], arr[min]);
            heapifyDown(min);
        }
    }

    void heapifyUp(int i)
    {
        if (i > 0)
        {
            int p = (i - 1) / 2; // Parent index
            if (arr[p] > arr[i])
            {
                swap(arr[i], arr[p]);
                heapifyUp(p);
            }
        }
    }

    void increaseSize()
    {
        int *newArr = new int[maxLength * 2];
        for (int i = 0; i < maxLength; i++)
        {
            newArr[i] = arr[i];
        }
        int *prevArr = arr;
        arr = newArr;
        maxLength *= 2;
        delete[] prevArr;
    }

public:
    MinHeap()
    {
        arr = new int[100];
        maxLength = 100;
        length = 0;
    }
    MinHeap(int initialSize)
    {
        arr = new int[initialSize];
        maxLength = initialSize;
        length = 0;
    }

    void push(int data)
    {
        if (length == maxLength - 1)
            increaseSize();
        arr[length++] = data;
        heapifyUp(length - 1);
    }

    void pop()
    {
        if (length == 0)
        {
            cout << "Error: Nothing to pop. Heap is empty.\n";
            return;
        }
        swap(arr[0], arr[length - 1]);
        length--;
        heapifyDown(0);
    }

    int top()
    {
        if (length == 0)
        {
            return INT_MIN;
        }
        return arr[0];
    }

    bool isEmpty()
    {
        return (length == 0);
    }

    ~MinHeap()
    {
        delete[] arr;
    }
};

int main()
{
    MinHeap mh;
    cout << boolalpha;
    cout << mh.top() << '\n';
    cout << mh.isEmpty() << '\n';
    mh.push(10);
    mh.push(20);
    mh.push(15);
    mh.push(12);
    mh.push(0);
    mh.push(25);
    cout << mh.isEmpty() << '\n';
    cout << mh.top() << '\n';
    mh.pop();
    cout << mh.top() << '\n';
    mh.pop();
    cout << mh.top() << '\n';
    mh.pop();
    cout << mh.top() << '\n';
    mh.pop();
    cout << mh.top() << '\n';
    mh.pop();
    cout << mh.top() << '\n';
    mh.pop();
    cout << mh.top() << '\n';
    mh.pop();
    cout << mh.isEmpty() << '\n';
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}