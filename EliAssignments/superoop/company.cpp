#include <iostream>
using namespace std;

const int baseSalary = 1e7;
const int hourlySalary = 1e5;

class Employee {
private:
    string name;
    string code;
    int age;
    int experience;
    string education;
public:
    Employee(
        string name,
        string code,
        int age,
        int experience,
        string education
    ) : name(name),
        code(code),
        age(age),
        experience(experience),
        education(education)
    {}
    virtual double salary(int hour) = 0;
};

class HourlyEmployee : public Employee {
public:
    double salary(int hour) {
        return hour * hourlySalary;
    }
};

class PermanentEmployee : public Employee {
public:
    double salary(int hour = 0) {
        return baseSalary + hour * hourlySalary;
    }
};