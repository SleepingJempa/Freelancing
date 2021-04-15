#include <iostream>

using namespace std;

typedef struct Student {
    float grade;
    int index;
} Student;

int main() {
    int n;
    cin >> n;

    Student student[n];

    for(int i = 0; i < n; i++) {
        cin >> student[i].grade;
        student[i].index = i;
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i + 1; j < n; j++) {
            if (student[j-1].grade > student[j].grade) {
                Student tmp = student[j];
                student[j] = student[j-1];
                student[j-1] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << i << ": " << student[i].grade << " [" << student[i].index << "]" << endl;
    }

    for(int i = 0; i < n; i++) {
        if (student[i].grade >= 10) {
            if (i > 1) {
                cout << "Second failed student got " << student[i-2].grade << endl;
            }

            else {
                cout << "There is no second grade" << endl;
            }
            break;
        }
    }
}