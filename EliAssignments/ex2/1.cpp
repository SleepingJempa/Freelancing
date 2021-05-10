#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

typedef struct Date Date;

int days(int month) {
    int d = 0;

    if (month > 6) {
        d += 6 * 30;
        month -= 6;
    } else {
        d += month * 30;
        month = 0;
    }

    d += month * 31;

    return d;
}

int distance(Date from, Date to) {
    return (
        (to.year - from.year) * 365 +
        (days(to.month) - days(from.month)) +
        (to.day - from.day)
    );
}

void getDate(Date &date) {
    cin >> date.year >> date.month >> date.day;
}

int main() {
    Date now, birth;

    cout << "Enter today's date: (Format: Y M D)" << endl;
    getDate(now);
    cout << "Enter the birth date: (Format: Y M D)" << endl;
    getDate(birth);

    cout << "The days have been spent from the birth date: " << distance(birth, now) << endl;
}