#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Car
{
    int registrationID;

protected:
    int topSpeed;
    int color;

    int getRegID()
    {
        return registrationID;
    }

public:
    string name;
    int cost;

    Car(string name, int cost)
    {
        this->name = name;
        this->cost = cost;
        srand(time(NULL));
        this->registrationID = rand() % 999999 + 100000;
    }

    void setTopSpeed(int speed)
    {
        if (speed > 0)
            topSpeed = speed;
    }

    void setColor(int color)
    {
        this->color = color;
    }
};

class ElectricCar : public Car
{
    string batteryType;

public:
    ElectricCar(string name, int cost, string batteryType) : Car(name, cost)
    {
        this->batteryType = batteryType;
    }

    void printInfo()
    {
        cout << "\nPrinting details about the Electric Vehicle\n";
        cout << "Registration ID: " << getRegID() << '\n';
        cout << "Name: " << name << '\n';
        cout << "Cost: " << cost << '\n';
        cout << "Top Speed: " << topSpeed << '\n';
        cout << "Battery Type: " << batteryType << '\n';
    }
};

int main()
{
    ElectricCar e1("BMW iX", 11600000, "Lithium Ion");
    e1.setTopSpeed(300);
    e1.printInfo();
}