#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility> // pair
using namespace std;

class Graph // Assuming that graph vertex numbering starts from 1
{
    vector<vector<int>> adj;

public:
    Graph(int numVertices)
    {
        // Initialise matrix of size (|v| + 1) * (|v| + 1) with each cell set to 0 initially
        adj = vector<vector<int>>(numVertices + 1, vector<int>(numVertices + 1, 0));
    }

    Graph(int numVertices, vector<pair<int, int>> edges)
    {
        adj = vector<vector<int>>(numVertices + 1, vector<int>(numVertices + 1, 0));

        for (pair<int, int> edge : edges)
            addEdge(edge.first, edge.second);
    }

    void addEdge(int firstVtx, int secondVtx)
    {
        if (firstVtx > adj.size() || secondVtx > adj.size())
            cout << "Error: One or more vertices are not present in the graph\n";

        adj[firstVtx][secondVtx] = 1;
        adj[secondVtx][firstVtx] = 1;
    }

    void addVertex()
    {
        for (int i = 0; i < adj.size(); i++) // Insert one additional column in all the prev rows
            adj[i].push_back(0);

        adj.push_back({});                             // Create an empty vector for the new row
        adj[adj.size() - 1] = vector<int>(adj.size()); // Initialise the new row with 0s
        cout << "Vertex " << adj.size() - 1 << " added\n";
    }

    void printAdjacencyMatrix()
    {
        cout << '\t';
        for (int i = 1; i < adj.size(); i++) // Printing col numbers
            cout << i << "  ";
        cout << "\n\n";

        for (int i = 1; i < adj.size(); i++)
        {
            cout << i << "\t"; // Row count
            for (int j = 1; j < adj[0].size(); j++)
            {
                cout << adj[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printBfs(int start = 1)
    {
        if (start >= adj.size())
            return;

        unordered_set<int> visited;
        queue<int> q;
        visited.insert(start);
        q.push(start);
        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int currVtx = q.front();
            q.pop();
            cout << currVtx << " ";
            for (int i = 1; i < adj.size(); i++)
            {
                if (adj[currVtx][i] != 0 && visited.count(i) == 0)
                {
                    q.push(i);
                    visited.insert(i);
                }
            }
        }
        cout << endl;
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
            int i = 0;
            while (i < adj.size())
            {
                if (adj[currVtx][i] != 0 && visited.count(i) == 0)
                {
                    s.push(i);
                }
                i++;
            }
        }
        cout << "(Iterative)\n";
    }

    void printDfsRecursive(int start, unordered_set<int> &visited)
    {
        cout << start << " ";
        visited.insert(start);

        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[start][i] != 0 && visited.count(i) == 0)
            {
                printDfsRecursive(i, visited);
            }
        }
    }
    void printDfsRecursive(int start = 1)
    {
        if (start >= adj.size())
            return;

        unordered_set<int> visited;
        cout << "DFS Traversal: ";
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
    g1->printAdjacencyMatrix();
    g1->printBfs();
    g1->printDfs();
    g1->printDfsRecursive();
}
