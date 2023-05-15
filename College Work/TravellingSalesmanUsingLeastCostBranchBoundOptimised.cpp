#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int upperBound = INT_MAX;

class MatNode
{
    vector<vector<int>> matrix;
    vector<int> visited;
    int lVal;
    int nodeIdx;

public:
    MatNode(vector<vector<int>> matrix, vector<int> visited, int lVal, int nodeIdx)
        : matrix(matrix), visited(visited), lVal(lVal), nodeIdx(nodeIdx) {}

    friend bool operator<(const MatNode &m1, const MatNode &m2);
    friend void reduceMatrix(MatNode &m);
    friend MatNode newNode(MatNode m, int i, int j);
    friend void TSP(const vector<vector<int>> &input, priority_queue<MatNode> &nodes);

    void print()
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == INT_MAX)
                    cout << "\xEC\t";
                else
                    cout << matrix[i][j] << "\t";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    int getCost()
    {
        return lVal;
    }

    int getIdx()
    {
        return nodeIdx;
    }
};

bool operator<(const MatNode &m1, const MatNode &m2)
{
    return m1.lVal > m2.lVal;
}

void reduceMatrix(MatNode &m)
{
    int totalReduction = 0;

    // Reducing rows
    for (int i = 0; i < m.matrix.size(); i++)
    {
        int reduction = m.matrix[i][0];
        for (int j = 1; j < m.matrix[0].size(); j++)
            reduction = min(reduction, m.matrix[i][j]);
        if (reduction == INT_MAX)
            reduction = 0;
        totalReduction += reduction;

        for (int j = 0; j < m.matrix[0].size(); j++)
        {
            if (reduction == 0)
                continue;
            if (m.matrix[i][j] != INT_MAX)
                m.matrix[i][j] -= reduction;
        }
    }

    // Reducing columns
    for (int j = 0; j < m.matrix[0].size(); j++)
    {
        int reduction = m.matrix[0][j];
        for (int i = 1; i < m.matrix.size(); i++)
            reduction = min(reduction, m.matrix[i][j]);
        if (reduction == INT_MAX)
            reduction = 0;
        totalReduction += reduction;

        for (int i = 0; i < m.matrix.size(); i++)
        {
            if (reduction == 0)
                continue;
            if (m.matrix[i][j] != INT_MAX)
                m.matrix[i][j] -= reduction;
        }
    }
    m.lVal += totalReduction;
}

MatNode newNode(MatNode m, int i, int j)
{
    m.lVal += m.matrix[i - 1][j - 1];
    m.visited.push_back(i);
    m.nodeIdx = j;
    for (int col = 0; col < m.matrix[0].size(); col++)
        m.matrix[i - 1][col] = INT_MAX;

    for (int row = 0; row < m.matrix.size(); row++)
        m.matrix[row][j - 1] = INT_MAX;

    for (int element : m.visited)
        m.matrix[j - 1][element - 1] = INT_MAX;

    return m;
}

void TSP(const vector<vector<int>> &input, priority_queue<MatNode> &nodes)
{
    MatNode finalAnswer = MatNode({{}}, {}, 0, 0);
    MatNode initial = MatNode(input, {}, 0, 1);
    reduceMatrix(initial);

    nodes.push(initial);
    initial.print();
    cout << initial.getCost() << "\n\n";
    cout << "Initial\n\n";
    cout << "------------------------------------\n";
    MatNode eNode = nodes.top();
    nodes.pop();

    int currIdx = eNode.getIdx();
    while (true)
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (eNode.matrix[currIdx - 1][i] != INT_MAX)
            {
                MatNode temp = newNode(eNode, currIdx, i + 1);
                reduceMatrix(temp);
                nodes.push(temp);
                temp.print();
                for (int i = 0; i < temp.visited.size(); i++)
                    cout << temp.visited[i] << " -> ";
                cout << i + 1 << '\n';
                cout << "Cost: " << temp.getCost() << "\n\n";
                cout << "------------------------------------\n";
            }
        }
        eNode = nodes.top();
        currIdx = eNode.getIdx();
        nodes.pop();
        if (eNode.visited.size() == input.size() - 1) // Leaf node reached, update upper bound
        {
            if (eNode.lVal < upperBound)
            {
                upperBound = eNode.lVal;
                finalAnswer = eNode;
            }
            else
                break;
        }
        MatNode topNode = nodes.top();
        if (topNode.getCost() > upperBound)
            break;
    }
    cout << "------------------------------------";
    cout << "\nThe most optimum path for the above TSP problem is:\n";
    for (int i = 0; i < finalAnswer.visited.size(); i++)
        cout << finalAnswer.visited[i] << " -> ";
    cout << finalAnswer.getIdx() << '\n';
    cout << "Optimum Cost: " << finalAnswer.getCost() << '\n';
    cout << "------------------------------------\n";
}

int main()
{
    priority_queue<MatNode> nodes;
    vector<vector<int>> input = {
        {INT_MAX, 20, 30, 10, 11},
        {15, INT_MAX, 16, 4, 2},
        {3, 5, INT_MAX, 2, 4},
        {19, 6, 18, INT_MAX, 3},
        {16, 4, 7, 16, INT_MAX},
    };

    TSP(input, nodes);
}