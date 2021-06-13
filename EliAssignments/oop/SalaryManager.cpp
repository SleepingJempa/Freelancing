#include <iostream>

using namespace std;

class SalaryManager
{
private:
    float salary;
    float increase_ratio;
public:
    SalaryManager(int salary, int increase_ratio) : salary(salary), increase_ratio(increase_ratio) {};
    float salaryAfter(int months);
};

float SalaryManager::salaryAfter(int months) {
    int current_salary = salary;
    float result = 0;

    while(months > 12) {
        result += current_salary;
        current_salary *= 1 + increase_ratio;
        months -= 12;
    }

    result += ((float)(months) / 12) * current_salary;
    return result;
}

int main() {
    SalaryManager sm(1000, 0.01);
    cout << sm.salaryAfter(25) << endl;
}