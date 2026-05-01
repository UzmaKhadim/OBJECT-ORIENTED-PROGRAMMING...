#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
protected:
    string vehicleName;

public:
    Vehicle(string v)
    {
        vehicleName = v;
        cout << "Vehicle Constructor Called" << endl;
        cout << "Vehicle Name: " << vehicleName << endl;
    }
};
class Car : public Vehicle
{
protected:
    string carModel;

public:
    Car(string v, string c) : Vehicle(v)
    {
        carModel = c;
        cout << "Car Constructor Called" << endl;
        cout << "Car Model: " << carModel << endl;
    }
};
class ElectricCar : public Car
{
private:
    int batteryCapacity;

public:
    ElectricCar(string v, string c, int b) : Car(v, c)
    {
        batteryCapacity = b;
        cout << "ElectricCar Constructor Called" << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

int main()
{
    ElectricCar e("Tesla", "Model S", 100);

    return 0;
}
