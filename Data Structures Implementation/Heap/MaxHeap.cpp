#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;
    int length;
    int maxLength;

    void heapifyDown(int i)
    {
        int l = (i * 2) + 1; // Left child index
        int r = (i * 2) + 2; // Right child index
        int max = i;

        if (l < length && arr[l] > arr[i])
        {
            max = l;
        }
        if (r < length && arr[r] > arr[max])
        {
            max = r;
        }
        if (max != i)
        {
            swap(arr[max], arr[i]);
            heapifyDown(max);
        }
    }

    void heapifyUp(int i)
    {
        if (i >= 1)
        {
            int p = (i - 1) / 2; // Parent index
            if (arr[p] < arr[i])
            {
                swap(arr[p], arr[i]);
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
    MaxHeap()
    {
        arr = new int[100];
        maxLength = 100;
        length = 0;
    }
    MaxHeap(int initialSize)
    {
        arr = new int[initialSize];
        maxLength = initialSize;
        length = 0;
    }

    void push(int data)
    {
        if (length == maxLength - 1) // Heap array is full
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

    ~MaxHeap()
    {
        delete[] arr;
    }
};

int main()
{
    MaxHeap mh;
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
    while (!mh.isEmpty())
    {
        cout << mh.top() << '\n';
        mh.pop();
    }
    mh.pop();
    cout << mh.isEmpty() << '\n';
}