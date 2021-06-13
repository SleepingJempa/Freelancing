#include <iostream>

using namespace std;

class Employee
{
private:
    string firstName;
    string lastName;
    int salary;
public:
    Employee(string firstName, string lastName, int salary);
    string getFirstName();
    void setFirstName(string firstName);
    string getlastName();
    void setlastName(string lastName);
    int getSalary();
    void setSalary(int salary);
    void showInfo();
   
};

void Employee::showInfo(){
    cout << firstName << endl;
    cout << lastName << endl;
    cout << salary << endl;
}


Employee::Employee(string firstName, string lastName, int salary)
{
    if (salary < 0 ){
        salary = 0;
    }
    this->firstName = firstName;
    this->lastName = lastName;
    this->salary = salary;
}

string Employee::getFirstName(){
    return firstName;
}

void Employee::setFirstName(string firstName){
    this->firstName = firstName;
}

string Employee::getlastName(){
    return lastName;
}

void Employee::setlastName(string lastName){
    this->lastName = lastName;
}

int Employee::getSalary(){
    return salary;
}

void Employee::setSalary(int salary){
    this->salary = salary;
}

int yearly(Employee &e){
    return 12 * e.getSalary();
}

void raise(Employee &e){
    e.setSalary(e.getSalary() * 110 / 100);
}



int main() {
    Employee emp("abbas", "boazar",1000);
    emp.showInfo();
    emp.setSalary(3000);
    emp.setFirstName("abass");
    emp.setlastName("masoomi");
    emp.showInfo();
    cout << "Yearly salary: " << yearly(emp) << endl;
    raise(emp);
    emp.showInfo();
    
}