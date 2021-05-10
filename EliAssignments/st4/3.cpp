#include <iostream>

using namespace std;

struct Employee {
    string code;
    string firstname;
    string lastname;
    int age;
    float hour_income;
    int hour_in_month;
    float total_income;
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    struct Student em[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the code: ";
        cin >> em[i].code;
        cout << "Enter the firstname: ";
        cin >> em[i].firstname;
        cout << "Enter the lastname: ";
        cin >> em[i].lastname;
        cout << "Enter the age: ";
        cin >> em[i].age;
        cout << "Enter the income per hour: ";
        cin >> em[i].hour_income;
        cout << "Enter the third hour in month: ";
        cin >> em[i].hour_in_month;
    }

    for(int i = 0; i < n; i++) {
        em[i].total_income = em[i].hour_income * em[i].hour_in_month;
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if (em[j].total_income > em[j+1].total_income) {
                struct Employee s = em[j];
                em[j] = em[j+1];
                em[j+1] = s;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << em[i].firstname << " " << em[i].lastname << " " << em[i].code << " " << em[i].age << " years old " << em[i].total_income << endl;
    }
}