// # Input
// s = input().split()
// q = int(s[0])

// def index(c):
//     return ['L', 'M', 'R'].index(c)

// def rev(i):
//     return ['L', 'M', 'R'][i]

// ans = index(s[1])

// for i in range(q):
//     x, y = map(index, input().split())
//     if ans in [x, y]:
//         ans = x + y - ans

// print(rev(ans))

#include <iostream>

using namespace std;

int main() {
    int q;
    char l;
    cin >> q;
    cin >> l;

    char r = l;

    for(int i = 0; i < q; i++) {
        char f, t;
        cin >> f >> t;

        if (r == f || r == t) r = f + t - r;
    }

    cout << (char)r;
}