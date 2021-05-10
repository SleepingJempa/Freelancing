#include <iostream>

using namespace std;

struct Book {
    string author;
    float cost;
    string title;
};

int main() {
    const int n = 10;

    struct Book books[n];

    for(int i = 0; i < n; i++) {
        cin >> books[i].author >> books[i].cost >> books[i].title;
    }

    for(int i = 0; i < n; i++) {
        cout << "\"" << books[i].author << "\"" << books[i].cost << "costs \"" << books[i].title << "\"";
    }
}