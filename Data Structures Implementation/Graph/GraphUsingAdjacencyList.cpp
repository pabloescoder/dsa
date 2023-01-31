#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
using namespace std;

class Graph // Assuming that graph vertex numbering starts from 1
{
    vector<vector<int>> adj;

public:
    Graph(int vertices, vector<pair<int, int>> edges)
    {
        adj = vector<vector<int>>(vertices + 1);
        for (auto edge : edges)
            addEdge(edge.first, edge.second);
    }

    void addEdge(int firstVtx, int secondVtx)
    {
        if (firstVtx >= adj.size() || secondVtx >= adj.size())
            cout << "Error: One or more vertices are not present in the graph\n";

        adj[firstVtx].push_back(secondVtx);
        adj[secondVtx].push_back(firstVtx);
    }

    void addVertex()
    {
        adj.push_back({});
        cout << "Vertex " << adj.size() - 1 << " added.\n";
    }

    void printAdjacencyList()
    {
        for (int i = 1; i < adj.size(); i++)
        {
            cout << i << '\t';
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << '\n';
        }
    }

    void printBfs(int start = 1)
    {
        if (start >= adj.size())
            return;

        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int currVtx = q.front();
            q.pop();
            cout << currVtx << " ";
            for (int i = 0; i < adj[currVtx].size(); i++)
            {
                if (visited.count(adj[currVtx][i]) == 0)
                {
                    q.push(adj[currVtx][i]);
                    visited.insert(adj[currVtx][i]);
                }
            }
        }
        cout << '\n';
    }

    void printDfs(int start = 1)
    {
        if (start >= adj.size())
            return;

        unordered_set<int> visited;
        stack<int> s;
        s.push(start);
        cout << "DFS Traversal: ";

        while (!s.empty())
        {
            int currVtx = s.top();
            s.pop();

            if (visited.count(currVtx) == 0)
            {
                cout << currVtx << " ";
                visited.insert(currVtx);
            }

            for (int i = 0; i < adj[currVtx].size(); i++)
            {
                if (visited.count(adj[currVtx][i]) == 0)
                    s.push(adj[currVtx][i]);
            }
        }
        cout << "(Iterative)\n";
    }

    void printDfsRecursive(int start, unordered_set<int> &visited)
    {
        cout << start << " ";
        visited.insert(start);

        for (int i = 0; i < adj[start].size(); i++)
        {
            if (visited.count(adj[start][i]) == 0)
            {
                printDfsRecursive(adj[start][i], visited);
            }
        }
    }
    void printDfsRecursive(int start = 1)
    {
        if (start >= adj.size())
            return;

        cout << "DFS Traversal: ";
        unordered_set<int> visited;
        printDfsRecursive(start, visited);
        cout << "(Recursive)\n";
    }
};

int main()
{
    Graph *g1 = new Graph(9, {{1, 2},
                              {1, 4},
                              {4, 3},
                              {2, 3}});
    g1->addVertex();
    g1->addEdge(3, 9);
    g1->addEdge(3, 10);
    g1->addEdge(2, 8);
    g1->addEdge(7, 8);
    g1->addEdge(2, 5);
    g1->addEdge(7, 5);
    g1->addEdge(2, 7);
    g1->addEdge(8, 5);
    g1->addEdge(6, 5);
    cout << '\n';
    g1->printAdjacencyList();
    g1->printBfs();
    g1->printDfs();
    g1->printDfsRecursive();
}