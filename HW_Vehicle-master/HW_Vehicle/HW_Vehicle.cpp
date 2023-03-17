#include <iostream>
using namespace std;

/*
Реализовать иерархию классов "Транспортное средство".
Базовый класс - транспорт, производные - самолёт, судно, грузовик, велосипед и легковой автомобиль.
Метод вывода и метод расхода топлива реализовать как virtual.
Реализовать меню для создания объектов.
Объекты создаются через единственный указатель на базовый класс
*/

// Base class vehicle
class Vehicle {
public:
    virtual void Output() {};
    virtual void FuelConsumption() {};
};

// Derived classes
class Airplane : public Vehicle {
public:
    void Output() {
        cout << "Airplane created\n";
    }
    void FuelConsumption() {
        cout << "Fuel Consumption - Airplane = 15 000 LT\n";
    }
};

class Ship : public Vehicle {
public:
    void Output() {
        cout << "Ship created\n";
    }
    void FuelConsumption() {
        cout << "Fuel Consumption - Ship = 10 000 LT\n";
    }
};

class Truck : public Vehicle {
public:
    void Output() {
        cout << "Truck created\n";
    }
    void FuelConsumption() {
        cout << "Fuel Consumption - Truck = 5 000 LT\n";
    }
};

class Bicycle : public Vehicle {
public:
    void Output() {
        cout << "Bicycle created\n";
    }
    void FuelConsumption() {
        cout << "Fuel Consumption - Bicycle = 200 LT\n";
    }
};

class Car : public Vehicle {
public:
    void Output() {
        cout << "Car created\n";
    }
    void FuelConsumption() {
        cout << "Fuel Consumption - Car\n = 400 LT";
    }
};

// Main Function
int main()
{
    Vehicle* Obj_Vech[10];

    int choice;

    while (1) {
        cout << "Menu\n";
        cout << "1. Airplane\n";
        cout << "2. Ship\n";
        cout << "3. Truck\n";
        cout << "4. Bicycle\n";
        cout << "5. Car\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            break;
        }

        switch (choice) {
        case 1: Obj_Vech[choice - 1] = new Airplane;
            break;
        case 2: Obj_Vech[choice - 1] = new Ship;
            break;
        case 3: Obj_Vech[choice - 1] = new Truck;
            break;
        case 4: Obj_Vech[choice - 1] = new Bicycle;
            break;
        case 5: Obj_Vech[choice - 1] = new Car;
            break;
        default: cout << "Invalid choice\n";
            break;
        }

        Obj_Vech[choice - 1]->Output();
        Obj_Vech[choice - 1]->FuelConsumption();
    }

    delete *Obj_Vech;

    return 0;

}
