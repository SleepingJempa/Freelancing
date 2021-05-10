#include <iostream>
#include <string>

using namespace std;

string read_string() { string s; cin >> s; return s; }

string no_word_2(string s) {
    // avalin khate fasele
    int p = s.find(' ');

    // age vojod nadasht
    if (p == -1) {
        return (s.length() == 2 ? "" : s);
    }

    // ghablo bad az space
    string before = s.substr(0, p+1);
    string after = s.substr(p+1);

    // be soorate bazgashti
    // `before` yek space dar akhar darad pas bayad ==3 check beshe
    if (before.length() == 2 + 1 /* one whitespace */) {
        return no_word_2(after);
    } else {
        return before + no_word_2(after);
    }
}

void print(string s) { cout << s << endl; }

int main() {
    string s;

    getline(cin, s);

    string w = no_word_2(s);
    print(w);
}