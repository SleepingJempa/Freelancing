#include <iostream>

using namespace std;

struct Student {
    string code;
    string firstname;
    string lastname;
    float grade;
    float lessons[3];
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    struct Student st[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the code: ";
        cin >> st[i].code;
        cout << "Enter the firstname: ";
        cin >> st[i].firstname;
        cout << "Enter the lastname: ";
        cin >> st[i].lastname;
        cout << "Enter the first lesson grade: ";
        cin >> st[i].lessons[0];
        cout << "Enter the second lesson grade: ";
        cin >> st[i].lessons[1];
        cout << "Enter the third lesson grade: ";
        cin >> st[i].lessons[2];
    }

    for(int i = 0; i < n; i++) {
        st[i].grade = (st[i].lessons[0] + st[i].lessons[1] + st[i].lessons[2]) / 3;
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if (st[j].grade < st[j+1].grade) {
                struct Student s = st[j];
                st[j] = st[j+1];
                st[j+1] = s;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << st[i].firstname << " " << st[i].lastname << " " << st[i].code << " " << st[i].grade << endl;
    }
}