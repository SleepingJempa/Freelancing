#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int n = 100;

    // arraye ha
    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[2 * n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // moratab saazi
    sort(a, a+n);
    sort(b, b+n);

    int i = 0;
    int j = 0;

    int cnt = 0;

    // az aaval roye arraye he paymayesh mikonim
    // chon sort shode mishe fahmid age a[i] < b[j]
    // onvaght a[i] too b[i] nis
    // age ham mosavi boodan har dota ro mibarim jelo
    while (i < n && j < n) {
        if (a[i] == b[j]) {
            while(i < n-1 && a[i] == a[i+1]) i++; i++;
            while(j < n-1 && b[j] == b[j+1]) j++; j++;
        }
        else if (a[i] < b[j]) {
            c[cnt++] = a[i++];
        } else {
            c[cnt++] = b[j++];
        }
    }

    // age yeki az arraye ha tamoom shod baghie azadaane add mishan
    while(i < n) {
        c[cnt++] = a[i++];
    }

    while(j < n) {
        c[cnt++] = b[j++];
    }

    // printing the result
    for(int i = 0; i < cnt; i++) {
        cout << c[i] << " \n"[i==cnt-1];
    }

    cout << cnt << endl;
}