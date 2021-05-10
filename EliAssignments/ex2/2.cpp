#include <iostream>
using namespace std;

enum Color {
    red = 0,
    blue = 1,
    yellow = 2
};

typedef struct Team {
    int code;
    string name;
    int foundation_year;
    int color;
} Team;

void getTeam(Team &team) {
    cin >> team.code >> team.name >> team.foundation_year >> team.color;
}

string colorName(int color) {
    switch (color)
    {
    case red:
        return "red";
    case blue:
        return "blue";
    case yellow:
        return "yellow";
    default:
        return "no color";
    }
}

void showTeam(const Team &team) {
    cout << "Team code: " << team.code << endl;
    cout << "Team foundation year: " << team.foundation_year << endl;
    cout << "Team color: " << colorName(team.color) << endl;
}

int main() {
    int n;

    cout << "Enter the number of teams: " << endl;
    cin >> n;

    Team *teams = new Team[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the " << i << "-th team info: (Format: code name foundation_year color)" << endl;
        cout << "Colors = [ 0: red, 1: blue, 2: yellow ]" << endl;
        getTeam(teams[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << "The " << i << "-th team info: " << endl;
        showTeam(teams[i]);
    }
}