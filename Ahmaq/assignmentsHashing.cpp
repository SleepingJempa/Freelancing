#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

typedef struct st {
    string name;
    int team;
    int index;
} Student;

int main() {
    srand(time(NULL));

    int n; // The number of students
    int s; // The number of presentation for each assignment
    int a; // The number of assignments
    cin >> n >> s >> a;

    vector<vector<Student>> students(n, vector<Student>(3));
    vector<vector<pair<int, int>>> grid(a, vector<pair<int, int>>(s));


    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            string name;
            cin >> name;

            students[i][j].name = name;
            students[i][j].team = i;
            students[i][j].index = j;
        }
    }


    int theI = 0;
    int theJ = 0;
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < s; j++) {
            grid[i][j] = {theI, theJ};

            theJ++;
            if (theJ == 3) {
                theJ = 0;
                theI++;
            }

            if (theI == n) {
                theI = 0;
            }
            // if (theI == n) no need to catch
        }
    }

    cout << "DEBUG" << endl;

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < s; j++) {
            int _i = rand() % a;
            int _j = rand() % s;
            swap(grid[i][j], grid[_i][_j]);
        }
    }

    for(int i = 0; i < a; i++) {
        cout << "A" << i << ":\t\t";
        for(int j = 0; j < s; j++) {
            int theI = grid[i][j].first;
            int theJ = grid[i][j].second;
            cout << students[theI][theJ].name << "\t";
        }
        cout << endl;
    }
}

/*
5 5 4
11 12 13
21 22 23
31 32 33
41 42 43
51 52 53
*/