#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    vector<string> tokens;
    map<int, int> mp;
    string s;

    while (cin >> s)  {
        tokens.push_back(s);
    }

    int k = stoi(s);

    for(int i = 0; i < tokens.size() - 2; i++) {
        tokens[i].pop_back();
    }

    vector<int> arr;

    for(int i = 0; i < tokens.size() - 1; i++) {
        arr.push_back(stoi(tokens[i]));
    }

    bool found = false;
    for(int i = 0; i < arr.size(); i++) {
        if (mp[k - arr[i]]) {
            printf("(%d, %d)\n", k-arr[i], arr[i]);
            found = true;
            break;
        } else {
            mp[arr[i]] += 1;
        }
    }

    if (! found) {
        cout << "not found" << endl;
    }
}