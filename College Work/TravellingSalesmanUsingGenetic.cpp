#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <unordered_set>
using namespace std;
void printVec(const vector<int> &nums);
void printPopulation(const vector<vector<int>> &pop, const vector<double> &fit);
int generation = 1;
int bestDistanceSoFar = INT_MAX;
vector<int> bestPathSoFar;

void randomiseOrder(vector<int> &nums, int start = 0)
{
    for (int i = start; i < nums.size(); i++)
    {
        int randIdx = (rand() % (nums.size() - i)) + i;
        swap(nums[i], nums[randIdx]);
    }
}

void generateInitialPopulation(vector<vector<int>> &populationArr, int numCities)
{
    vector<int> orderedSeq;
    for (int i = 2; i <= numCities; i++)
        orderedSeq.push_back(i);
    vector<int> temp;

    for (int i = 0; i < populationArr.size(); i++)
    {
        temp = orderedSeq;
        randomiseOrder(temp);
        populationArr[i] = temp;
    }
}

void calculateFitness(vector<vector<int>> &input, vector<vector<int>> &populationArr, vector<double> &fitnessArr)
{
    double cost = 0;
    for (int i = 0; i < populationArr.size(); i++)
    {
        int firstVertexIdx = populationArr[i][0] - 1;
        cost += input[0][firstVertexIdx]; // Add the cost of travelling from starting node to the second node
        for (int j = 0; j < populationArr[i].size() - 1; j++)
        {
            cost += input[populationArr[i][j] - 1][populationArr[i][j + 1] - 1];
        }
        int lastVertexIdx = populationArr[i][populationArr[i].size() - 1] - 1;
        cost += input[lastVertexIdx][0]; // Add the cost of travelling from the last node back to the starting node

        if (cost < bestDistanceSoFar)
        {
            bestDistanceSoFar = cost;
            bestPathSoFar = populationArr[i];
        }

        // Take the reciprocal of the cost for the fitness because higher cost should mean lower fitness
        fitnessArr[i] = 1 / cost;
        cost = 0;
    }
}

void normaliseFitness(vector<double> &fitnessArr)
{
    double sum = 0;
    for (double fitness : fitnessArr)
        sum += fitness;

    for (int i = 0; i < fitnessArr.size(); i++)
        fitnessArr[i] = fitnessArr[i] / sum;
}

vector<double> calculateCumulativeFitness(vector<double> &fitnessArr)
{
    vector<double> cumuFitnessArr(fitnessArr.size());
    cumuFitnessArr[0] = fitnessArr[0];
    for (int i = 1; i < fitnessArr.size(); i++)
        cumuFitnessArr[i] = cumuFitnessArr[i - 1] + fitnessArr[i];
    return cumuFitnessArr;
}

int rouletteWheel(vector<double> &cumuFitnessArr)
{
    double r = (double)rand() / RAND_MAX;
    for (int i = 0; i < cumuFitnessArr.size() - 1; i++)
    {
        if (r >= cumuFitnessArr[i] && r <= cumuFitnessArr[i + 1])
            return i + 1;
    }
    return 0;
}

vector<vector<int>> crossover(vector<int> &parent1, vector<int> &parent2, double crossoverRate)
{
    if ((double)rand() / RAND_MAX < crossoverRate)
    {
        int n = parent1.size();
        int crossoverPoint = rand() % n;

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
        return {parent1, parent2};
    }
}

void mutate(vector<int> &child, double mutationRate)
{
    for (int i = 0; i < child.size(); i++)
    {
        if ((double)rand() / RAND_MAX < mutationRate)
        {
            int randIdx = rand() % child.size();
            swap(child[i], child[randIdx]);
        }
    }
}

void nextGeneration(vector<vector<int>> &populationArr, vector<double> &cumuFitnessArr)
{
    int popSize = populationArr.size();
    vector<vector<int>> newPopulationArr(popSize);
    int newChildIdx = 0;
    while (newChildIdx != newPopulationArr.size())
    {
        int idx1 = rouletteWheel(cumuFitnessArr);
        int idx2 = rouletteWheel(cumuFitnessArr);
        vector<int> parent1 = populationArr[idx1];
        vector<int> parent2 = populationArr[idx2];
        vector<vector<int>> children = crossover(parent1, parent2, 0.85); // Crossover rate is generally 80-90%
        mutate(children[0], 0.05);                                        // Mutation rate is generally 1-5%
        mutate(children[1], 0.05);
        newPopulationArr[newChildIdx++] = children[0];
        newPopulationArr[newChildIdx++] = children[1];
    }
    generation++;
    populationArr = newPopulationArr;
}

int main()
{
    srand(time(0));
    vector<vector<int>> input = {
        {INT_MAX, 20, 30, 10, 11, 15, 13, 2, 12, 1},
        {15, INT_MAX, 16, 4, 2, 20, 1, 7, 18, 11},
        {3, 5, INT_MAX, 2, 4, 9, 21, 8, 9, 14},
        {19, 6, 18, INT_MAX, 3, 10, 9, 20, 15, 21},
        {16, 4, 7, 16, INT_MAX, 19, 1, 13, 11, 2},
        {1, 14, 8, 12, 20, INT_MAX, 2, 9, 13, 10},
        {5, 12, 9, 4, 8, 22, INT_MAX, 12, 19, 22},
        {19, 13, 5, 13, 11, 31, 8, INT_MAX, 11, 6},
        {13, 29, 17, 6, 9, 15, 7, 13, INT_MAX, 24},
        {6, 14, 9, 26, 29, 13, 3, 21, 12, INT_MAX},
    };
    int numCities = input.size();
    int popSize = 100;        // Generally 10x the number of cities
    int maxGenerations = 150; // Start with 100 or 1000 and adjust as required
    vector<vector<int>> population(popSize);
    vector<double> fitnessArr(popSize);
    vector<double> cumuFitnessArr(popSize);
    generateInitialPopulation(population, numCities);
    for (int i = 0; i < maxGenerations; i++)
    {
        calculateFitness(input, population, fitnessArr);
        normaliseFitness(fitnessArr);
        cumuFitnessArr = calculateCumulativeFitness(fitnessArr);
        printPopulation(population, fitnessArr);
        nextGeneration(population, cumuFitnessArr);
    }
}

void printVec(const vector<int> &nums)
{
    // Appends 1 to the front and back while printing
    cout << 1 << " ";
    for (int elem : nums)
        cout << elem << " ";
    cout << 1;
}

void printPopulation(const vector<vector<int>> &pop, const vector<double> &fit)
{
    cout << "--------------------------------------------------------\n";
    cout << "Population for Generation " << generation << '\n';
    if (generation < 3 || generation > 148) // Printing the population only when gen < 5 or gen > 145
    {
        for (int i = 0; i < pop.size(); i++)
        {
            printVec(pop[i]);
            cout << "\t(Fitness: " << fit[i] << ")\n";
        }
        cout << '\n';
    }
    cout << "Best Distance So Far: " << bestDistanceSoFar << '\n';
    cout << "Best Path So Far: ";
    cout << 1 << " -> ";
    for (int i = 0; i < bestPathSoFar.size(); i++)
        cout << bestPathSoFar[i] << " -> ";
    cout << "1\n";
    cout << "--------------------------------------------------------\n";
}
