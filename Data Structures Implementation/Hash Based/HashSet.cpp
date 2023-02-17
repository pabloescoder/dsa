#include <iostream>
#include <vector>
using namespace std;

class HashSet
{
    int numOfBuckets;
    vector<int> *container;

    // This is a very basic hash function, real implementations use complicated & efficient Hash Fns
    int hashFunction(int data)
    {
        return (data % numOfBuckets);
    }

public:
    HashSet()
    {
        numOfBuckets = 10;
        container = new vector<int>[numOfBuckets];
    }
    HashSet(int bucketSize)
    {
        numOfBuckets = bucketSize;
        container = new vector<int>[numOfBuckets];
    }

    bool search(int data)
    {
        int index = hashFunction(data);
        for (auto it = container[index].begin(); it != container[index].end(); it++)
        {
            if (*it == data)
                return true;
        }
        return false;
    }

    void insert(int data)
    {
        if (!search(data))
        {
            int index = hashFunction(data);
            container[index].push_back(data);
            cout << data << " inserted into the HashSet.\n";
            return;
        }
        cout << data << " is already present in the HashSet.\n";
    }

    void remove(int data)
    {
        int index = hashFunction(data);
        for (auto it = container[index].begin(); it != container[index].end(); it++)
        {
            if (*it == data)
            {
                container[index].erase(it);
                cout << data << " removed from the HashSet.\n";
                return;
            }
        }
        cout << data << " is not present in the HashSet.\n";
    }

    int size()
    {
        int n = 0;
        for (int i = 0; i < numOfBuckets; i++)
        {
            n += container[i].size();
        }
        return n;
    }

    bool empty()
    {
        return (size() == 0);
    }

    void print()
    {
        for (int i = 0; i < numOfBuckets; i++)
        {
            for (int i : container[i])
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    ~HashSet()
    {
        delete[] container;
    }
};

int main()
{
    HashSet hs;
    cout << boolalpha;
    cout << "Is the HashSet empty? " << hs.empty();
    cout << "Size: " << hs.size() << endl;
    hs.insert(10);
    hs.insert(25);
    hs.insert(12);
    hs.insert(22);
    hs.insert(8);
    hs.insert(8);
    hs.insert(8);
    hs.print();
    hs.remove(8);
    hs.remove(25);
    hs.remove(100);
    hs.print();
    cout << "Size: " << hs.size() << endl;
    cout << "Is the HashSet empty? " << hs.empty() << endl;
    cout << "Is 10 present in the HashSet? " << hs.search(10) << endl;
    cout << "Is 27 present in the HashSet? " << hs.search(27) << endl;
}