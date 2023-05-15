#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <ctime>
using namespace std;
void printVec(vector<int> &vec);

vector<vector<int>> crossover(vector<int> &parent1, vector<int> &parent2, double crossoverRate)
{
    double randomNum = (double)rand() / RAND_MAX;
    cout << "Random num generated is: " << randomNum << '\n';
    if (randomNum < crossoverRate)
    {
        cout << randomNum << " < " << crossoverRate << "\nCrossover will happen!\n";
        int n = parent1.size();
        int crossoverPoint = rand() % n;
        cout << "Crossover Point (k) = " << crossoverPoint << '\n';

        // Right limits are exclusive.
        // Child 1 has left part of parent1 from 0 to crossPoint and right part of parent2 from crossPoint to n.
        // Child 2 has left part of parent2 from 0 to crossPoint and right part of parent1 from crossPoint to n.

        // Creating child1
        vector<int> child1(parent1.begin(), next(parent1.begin(), crossoverPoint));
        unordered_set<int> remNodes1;
        for (int i = crossoverPoint; i < n; i++)
            remNodes1.insert(parent1[i]);
        for (int i = 0; i < n; i++)
        {
            if (remNodes1.count(parent2[i]) != 0)
                child1.push_back(parent2[i]);
            if (child1.size() == n)
                break;
        }

        // Creating child2
        vector<int> child2(parent2.begin(), next(parent2.begin(), crossoverPoint));
        unordered_set<int> remNodes2;
        for (int i = crossoverPoint; i < n; i++)
            remNodes2.insert(parent2[i]);
        for (int i = 0; i < n; i++)
        {
            if (remNodes2.count(parent1[i]) != 0)
                child2.push_back(parent1[i]);
            if (child2.size() == n)
                break;
        }
        return {child1, child2};
    }
    else
    {
        cout << randomNum << " is not less than " << crossoverRate << "\nCrossover will NOT happen.\n";
        return {parent1, parent2};
    }
}

int main()
{
    srand(time(0));
    vector<int> parent1 = {5, 1, 3, 4, 2, 6};
    vector<int> parent2 = {1, 3, 2, 6, 5, 4};

    cout << "Parent 1: ";
    printVec(parent1);
    cout << "Parent 2: ";
    printVec(parent2);

    double crossoverRate = 0.85;
    cout << "Crossover rate is " << crossoverRate << '\n';
    vector<vector<int>> children = crossover(parent1, parent2, crossoverRate);

    cout << "Child 1: ";
    printVec(children[0]);
    cout << "Child 2: ";
    printVec(children[1]);
}

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}