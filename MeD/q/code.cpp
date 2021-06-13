#include <iostream>

using namespace std;

const int N = 3;

struct Studnet {
    string firstname;
    string lastname;
    string code;
    int birth_date[3];
    string address;
};

typedef struct Studnet Student;

void getStudents(Student* all, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Enter the first name: " << endl;
        cin >> all[i].firstname;
        cout << "Enter the last name: " << endl;
        cin >> all[i].lastname;
        cout << "Enter the code: " << endl;
        cin >> all[i].code;
        cout << "Enter the year of your birth: " << endl;
        cin >> all[i].birth_date[0];
        cout << "Enter the month of your birth: " << endl;
        cin >> all[i].birth_date[1];
        cout << "Enter the day of your birth: " << endl;
        cin >> all[i].birth_date[2];

        string city, postal_code;
        cout << "Enter the city: " << endl;
        cin >> city;
        cout << "Enter the postal code: " << endl;
        cin >> postal_code;

        all[i].address = city + postal_code;
    }
}

int age(Student s, int now[3]) {
    return now[0] - s.birth_date[0];
}

void show_info(Student* all, int n, int now[3]) {
    for(int i = 0; i < n; i++) {
        cout << all[i].code << "\t\t" << age(all[i], now) << endl;
    }
}

bool check(Student s, int now[3]) {
    for(int i = 0; i < 3; i++) {
        if (now[i] != s.birth_date[i]) return false;
    }
    return true;
}

int main() {
    Student all[N];

    getStudents(all, N);

    int now[3] = {1400, 2, 16};
    show_info(all, N, now);

    int year, month, day;
    cout << "Enter the current year: " << endl;
    cin >> year;
    cout << "Enter the month: " << endl;
    cin >> month;
    cout << "Enter the day: " << endl;
    cin >> day;

    int now[3] = {year, month, day};

    for(int i = 0; i < N; i++) {
        if (check(all[i], now)) {
                cout << "Happy birth day " << all[i].firstname << " " << all[i].lastname << endl;
            }
    }
}