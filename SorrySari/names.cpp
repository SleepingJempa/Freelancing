#include <iostream>
#include <vector>

using namespace std;

void count(vector<string> v) {
    int n = v.size();
    // اندازه آرایه پویا

    for(int i = 0; i < n; i++) {
        // اگر یک عضو از ارایه خالی نبود
        // تا اخر چک می کنیم که چند تا عضو مشابه بود
        // هر جا مشابه دیدیم ان عضو را خالی می کنیم تا دیگر چک نکنیم
        if (v[i] != "") {
            string current = v[i];
            // عضو فعلی
            int cnt = 0;
            // تعداد تکرار

            // حلقه ای برای چک کردن اعضای دیگر
            // نیازی به چک کردن اعضای قبلی نیست
            for(int j = i; j < n; j++) {
                if (current == v[j]) {
                    v[j] = "";
                    cnt++;
                }
            }

            cout << current << ": " << cnt << endl;
        }
    }
}

int main() {
    vector<string> names;
    // یک آرایه پویا برای ذخیره کردن اسامی

    string name;
    while(cin >> name) {
        // تا وقتی که ورودی داریم اسامی را در آرایه پویا می گذاریم
        // برای خارج شدن ابتدا دکمه زیر را فشار دهید
        // Ctrl + Z
        // و سپس
        // Enter
        names.push_back(name);
    }

    // تابع را صدا می زنیم
    count(names);
}