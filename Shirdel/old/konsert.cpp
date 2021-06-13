// t, a, b = map(int, input().split())

// x = t // (a + b + 2)
// y = t // (a + b + 2)
// m = t % (a + b + 2)
// x += int(m > 0)
// y += int(m > a)
// print(x, y)

#include <iostream>

using namespace std;

int main() {
    int t, a, b;
    cin >> t >> a >> b;

    int arar = (t / (a + b + 2));
    int mama = (t / (a + b + 2));

    int rem = t % (a + b + 2);

    if (rem > 0) arar++;
    if (rem > a) mama++;

    cout << arar << " " << mama << endl;
}