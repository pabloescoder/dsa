#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class HashMap // int -> string
{
    int numOfBuckets;
    vector<pair<int, string>> *container;

    // This is a very basic hash function, real implementations use complicated & efficient Hash Fns
    int hashFunction(int data)
    {
        return data % numOfBuckets;
    }

public:
    HashMap()
    {
        numOfBuckets = 10;
        container = new vector<pair<int, string>>[numOfBuckets];
    }
    HashMap(int bucketSize)
    {
        numOfBuckets = bucketSize;
        container = new vector<pair<int, string>>[numOfBuckets];
    }

    int search(int key)
    {
        int index = hashFunction(key);
        for (auto it = container[index].begin(); it != container[index].end(); it++)
        {
            if (it->first == key)
            {
                return true;
            }
        }
        return false;
    }

    string &operator[](int key) // Overloading the index operator so that we can get values by keys
    {
        int index = hashFunction(key);
        if (search(key))
        {
            for (auto it = container[index].begin(); it != container[index].end(); it++)
            {
                if (it->first == key)
                {
                    return it->second;
                }
            }
        }
        string emptyStr = "";
        string &emptyRef = emptyStr;
        return emptyRef;
    }

    void insert(const pair<int, string> &data)
    {
        int index = hashFunction(data.first);

        // Key not present, create new one
        if (!search(data.first))
        {
            container[index].push_back({data.first, data.second});
            cout << "Key " << data.first << " has been added with value " << data.second << '\n';
            return;
        }
        // Key present, rewrite value
        else
        {
            for (auto it = container[index].begin(); it != container[index].end(); it++)
            {
                if (it->first == data.first)
                {
                    it->second = data.second;
                    cout << "Key " << data.first << " is already present. Value rewritten.\n";
                    return;
                }
            }
        }
    }

    void remove(int key)
    {
        if (search(key))
        {
            int index = hashFunction(key);
            for (auto it = container[index].begin(); it != container[index].end(); it++)
            {
                if (it->first == key)
                {
                    container[index].erase(it);
                    cout << "Key " << it->first << " with data " << it->second << " removed from the HashSet.\n";
                    return;
                }
            }
        }
        else
        {
            cout << "Key " << key << " is not present in the HashMap.\n";
        }
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
            for (auto data : container[i])
            {
                cout << data.first << " -> " << data.second << '\n';
            }
        }
    }

    ~HashMap()
    {
        delete[] container;
    }
};

int main()
{
    HashMap hm;
    cout << boolalpha;
    cout << "Is the HashMap empty? " << hm.empty() << endl;
    cout << "Size: " << hm.size() << endl;
    hm.insert({10, "Ten"});
    hm.insert({25, "Twenty Five"});
    hm.insert({12, "Twelve"});
    hm.insert({22, "Twenty Two"});
    hm.insert({8, "Eig"});
    hm.insert({8, "Eigh"});
    hm.insert({8, "Eight"});
    hm.print();
    hm.remove(8);
    hm.remove(25);
    hm.remove(100);
    hm.print();
    cout << "Size: " << hm.size() << endl;
    cout << "Is the HashMap empty? " << hm.empty() << endl;
    cout << "Is Key 10 present in the HashMap? " << hm.search(10) << endl;
    cout << "Is Key 27 present in the HashMap? " << hm.search(27) << endl;
}