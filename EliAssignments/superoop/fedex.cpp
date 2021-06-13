#include <iostream>
using namespace std;

const int GoodsCost = 1e3;
const int PassengersCost = 1e4;

class Car {
private:
    int code;
    string tag;
    string color;
    string firstNameOfDriver;
    string lastNameOfDriver;
    int nationalCodeOfDriver;
public:
    Car(
        int code,
        string tag,
        string color,
        string firstNameOfDriver,
        string lastNameOfDriver,
        int nationalCodeOfDriver
    ) : code(code),
        tag(tag),
        color(color),
        firstNameOfDriver(firstNameOfDriver),
        lastNameOfDriver(lastNameOfDriver),
        nationalCodeOfDriver(nationalCodeOfDriver)
    {}
};

class Truck : public Car {
private:
    int weight;
public:
    Truck(
        int code,
        string tag,
        string color,
        string firstNameOfDriver,
        string lastNameOfDriver,
        int nationalCodeOfDriver,
        int weight
    ) : Car(
            code,
            tag,
            color,
            firstNameOfDriver,
            lastNameOfDriver,
            nationalCodeOfDriver
        ),
        weight(weight)
    {}
    int cost() {
        return weight * GoodsCost;
    }
};

class Bus : public Car {
private:
    int quantity;
public:
    Bus(
        int code,
        string tag,
        string color,
        string firstNameOfDriver,
        string lastNameOfDriver,
        int nationalCodeOfDriver,
        int quantity
    ) : Car(
            code,
            tag,
            color,
            firstNameOfDriver,
            lastNameOfDriver,
            nationalCodeOfDriver
        ),
        quantity(quantity)
    {}
    int cost() {
        return quantity * PassengersCost;
    }
};