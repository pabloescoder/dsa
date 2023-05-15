#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void printVec(const vector<double> &nums);
void printVecWith1(const vector<int> &nums);
void printPopulation(const vector<vector<int>> &pop, const vector<double> &fit);

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

int main()
{
    srand(time(0));

    // Generate a sample population
    // Starting vertex 1 and ending vertex 1 is not included as we don't want that to be shuffled
    vector<vector<int>>
        population = {
            {5, 2, 6, 3, 10, 4, 7, 8, 9},
            {8, 7, 10, 9, 4, 2, 5, 3, 6},
            {6, 8, 10, 4, 5, 7, 9, 2, 3},
            {2, 4, 9, 5, 10, 3, 6, 8, 7},
            {10, 4, 5, 9, 6, 2, 3, 8, 7},
        };

    vector<double> fitnessArr(population.size());
    // Generating random fitness values from 0 - 99 (inclusive)
    for (int i = 0; i < population.size(); i++)
        fitnessArr[i] = rand() % 100;

    printPopulation(population, fitnessArr);
    cout << "Fitness Array BEFORE normalisation:\n";
    printVec(fitnessArr);

    normaliseFitness(fitnessArr);
    cout << "Fitness Array AFTER normalisation:\n";
    printVec(fitnessArr);

    vector<double> cumuFitnessArr = calculateCumulativeFitness(fitnessArr);
    cout << "Cumulative Fitness Array:\n";
    printVec(cumuFitnessArr);

    int times = 5;
    cout << "Running Roulette Wheel " << times << " times:-\n";
    for (int i = 0; i < times; i++)
    {
        int idx = rouletteWheel(cumuFitnessArr);
        cout << "\nPopulation member with index " << idx << " selected\nie. ";
        printVecWith1(population[idx]);
        cout << " is selected\n";
    }
}

void printVec(const vector<double> &nums)
{
    for (double elem : nums)
        cout << elem << " ";
    cout << "\n\n";
}

void printVecWith1(const vector<int> &nums)
{
    // Appends 1 to the front and back while printing
    cout << 1 << " ";
    for (int elem : nums)
        cout << elem << " ";
    cout << 1;
}

void printPopulation(const vector<vector<int>> &pop, const vector<double> &fit)
{
    cout << "Displaying Population\n";
    for (int i = 0; i < pop.size(); i++)
    {
        printVecWith1(pop[i]);
        cout << "\t(Fitness: " << fit[i] << ")\n";
    }
    cout << '\n';
}