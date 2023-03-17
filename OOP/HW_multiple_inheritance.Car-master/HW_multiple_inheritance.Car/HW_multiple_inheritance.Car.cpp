#include <iostream>
#include <string>

using namespace std;

/*
Используя множественное наследование, разработать класс “Автомобиль”.
Автомобиль будет потомком для классов “Колеса”, “Двигатель”, “Двери”.
*/

class Wheels
{
protected:
    int numWheels;
    int wheelSize;

public:
    Wheels()
    {
        numWheels = 4;
        wheelSize = 16;
    }

    void show_Wheels()
    {
        cout
            << "___Wheels___" << endl
            << " Num wheels = " << numWheels << endl
            << " Size = " << wheelSize << endl;
    }
};

class Engine
{
protected:
    int numCylinders;
    int horsepower;
public:
    Engine()
    {
        numCylinders = 6;
        horsepower = 300;
    }
    void show_Engine()
    {
        cout
            << "___Engine___" << endl
            << " Num cylinders = " << numCylinders << endl
            << " Horsepower = " << horsepower << endl;
    }
};

class Doors
{
protected:
    int numDoors;
    int doorSize;
public:
    Doors()
    {
        numDoors = 4;
        doorSize = 30;
    }

    void show_Doors()
    {
        cout
            << "___Doors___" << endl
            << " Num doors = " << numDoors << endl
            << " Door Size = " << doorSize << endl;
    }
};

class Car : public Wheels, public Engine, public Doors
{
protected:
    string color;
    string model;
public:
    Car()
    {
        color = "Black";
        model = "AUDI";
    }
    void show_Car()
    {
        cout
            << "___Car___" << endl
            << " Color = " << color << endl
            << " Model = " << model << endl;

        Wheels::show_Wheels();
        Engine::show_Engine();
        Doors::show_Doors();
    }
};

int main()
{
    Car myCar;
    myCar.show_Car();

    return 0;
}
