#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

void addToMultiset(multiset<string> &ms, const string s) {
    stringstream ss(s);

    string t;
    while (ss >> t) {
        ms.insert(t);
    }
}

void printReversed(string s) {
    stringstream ss(s);
    string word;

    stack<string> words;

    while(ss >> word) {
        words.push(word);
    }

    while(!words.empty()) {
        cout << words.top() << " ";
        words.pop();
    }

    cout << endl;
}

int main() {
    string s;
    multiset<string> all;
    vector<string> lines;

    while(true) {
        getline(cin, s);
        if (s == "0") break;
        addToMultiset(all, s);
        lines.push_back(s);
    }

    for(string t : lines) {
        printReversed(t);
    }

    string bstring;
    int bcount = 0;
    for(string t : all) {
        if (all.count(t) > bcount) {
            bcount = all.count(t);
            bstring = t;
        }
    }

    cout << "Bishtrin tekrar: " << bstring << endl;
}