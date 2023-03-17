#include <iostream>

using namespace std;


/*
Реализовать иерархию классов "Транспортное средство".
В базовом классе реализовать набор чисто виртуальных методов
(ввод-вывод, расход топлива, получение стоимости, установка стоимости,
грузоподъёмность, количество мест для пассажиров).
Потомки переопределяют чисто виртуальные методы. Создать массив указателей базового класса.
Каждый элемент указывает на объект потомка.
Поочерёдно вызывая методы в переборном цикле, освобождаем память.
*/


class Vehicle
{
public:
    virtual void Input() = 0;                     // ввод
    virtual void Output() = 0;                    // вывод
    virtual double FuelConsumption() = 0;         // расход топлива
    virtual double GetCost() = 0;                 // получение стоимости
    virtual void SetCost(double cost) = 0;        // установка стоимости
    virtual int Payload() = 0;                    // грузоподъёмность
    virtual int PassengerSeats() = 0;             // количество мест для пассажиров

};


class Car : public Vehicle 
{
private:
    double fuelConsumption;                     
    double cost;                                
    int payload;                                
    int numPassengerSeats;                      
public:
    Car()
    {
        fuelConsumption = NULL;
        cost = NULL;
        payload = NULL;
        numPassengerSeats = NULL;
    }

    Car(double fuelConsumption, double cost, int payload, int numPassengerSeats) 
    {
        this->fuelConsumption = fuelConsumption;
        this->cost = cost;
        this->payload = payload;
        this->numPassengerSeats = numPassengerSeats;
    }
    void Input()
    {
        float fuel = NULL;
        float cost_new = NULL;
        int paylo = NULL;
        int numPass = NULL;

        cout << "Fuel Consumption: "; cin >> fuel;
        cout << "Cost: "; cin >> cost_new;
        cout << "Payload: "; cin >> paylo;
        cout << "Number of Passenger Seats: "; cin >> numPass;

        this->fuelConsumption = fuel;
        this->cost = cost_new;
        this->payload = paylo;
        this->numPassengerSeats = numPass;

    }
    void Output()
    {
        cout 
            << " ___CAR___ " << endl
            << "Fuel Consumption: " << fuelConsumption << endl
            << "Cost: " << cost << endl
            << "Payload: " << payload << endl
            << "Number of Passenger Seats: " << numPassengerSeats << endl;
    }
    double FuelConsumption()
    {
        cout << "\nFuel Consumption: " << fuelConsumption << endl;
        return fuelConsumption;
    }
    double GetCost()
    {
        cout << "\nCost: " << cost << endl;
        return cost;
    }
    void SetCost(double cost)
    {
        this->cost = cost;
        cout << "\nCost: " << cost;
    }
    int Payload()
    {
        cout << "\nPayload: " << payload << endl;
        return payload;
    }
    int PassengerSeats()
    {
        cout << "Number of Passenger Seats: " << numPassengerSeats << endl;
        return numPassengerSeats;
    }
};



int main()
{
    Vehicle* new_vehicle[1];
    new_vehicle[0] = new Car(15,32,1002,30);

    for (size_t i = 0; i < 1; i++)
    {
        new_vehicle[i]->Output();
        new_vehicle[i]->FuelConsumption();
        new_vehicle[i]->GetCost();
        new_vehicle[i]->SetCost(1400);
        new_vehicle[i]->Payload();
        new_vehicle[i]->PassengerSeats();
    }

    for (size_t i = 0; i < 1; i++)
    {
        delete new_vehicle[i];
    }

	return 0;
}
