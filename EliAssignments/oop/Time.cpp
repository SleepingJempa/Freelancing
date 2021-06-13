#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {};
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }
    void advance(int h, int m, int s);
    void reset() { hour = minute = second = 0; }
    void print();
    void printAmPm();
};

void Time::advance(int h, int m, int s) {
    second += s;
    if (second >= 60) {
        m++;
        second %= 60;
    }
    minute += m;
    if (minute >= 60) {
        h++;
        minute %= 60;
    }
    hour += h;
}

void Time::print() {
    if (hour < 10) {
        cout << "0" << hour;
    } else {
        cout << hour;
    }

    cout << ":";

    if (minute < 10) {
        cout << "0" << minute;
    } else {
        cout << minute;
    }

    cout << ":";
    
    if (second < 10) {
        cout << "0" << second;
    } else {
        cout << second;
    }
}

void Time::printAmPm() {
    bool flag = hour >= 12;
    hour %= 12;
    print();
    cout << " " << (flag ? "PM" : "AM") << endl;
}

int main() {
    Time t1(3, 14, 22);
    t1.printAmPm();

    Time t2(13, 2, 1);
    t2.printAmPm();
}