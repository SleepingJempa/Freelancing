#include <iostream>

using namespace std;


// Part Alef

typedef struct Personal_Info {
    string name;
    int national_code;
    string education;
} Personal_Info;

typedef struct Bank_Account {
    int id;
    float balance;
    Personal_Info owner;
} Bank_Account;

// Part Be

void sortInfo(Bank_Account *acc, int n) {
    // bubble sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            // the key of comparison
            if (acc[j].balance > acc[j+1].balance) {
                // swap

                int id = acc[j].id;
                float balance = acc[j].balance;
                string name = acc[j].owner.name;
                int national_code = acc[j].owner.national_code;
                string education = acc[j].owner.education;

                acc[j].id = acc[j+1].id;
                acc[j].balance = acc[j+1].balance;
                acc[j].owner.name = acc[j+1].owner.name;
                acc[j].owner.national_code = acc[j+1].owner.national_code;
                acc[j].owner.education == acc[j].owner.education;

                
                acc[j+1].id = id;
                acc[j+1].balance = balance;
                acc[j+1].owner.name = name;
                acc[j+1].owner.national_code = national_code;
                acc[j+1].owner.education == education;
            }
        }
    }
}

void findBelow(Bank_Account *acc, int n, float minBal) {
    cout << "People with more than " << minBal << " money" << endl;
    
    for(int i = 0; i < n; i++) {
        if (acc[i].balance >= minBal) {
            cout << acc[i].owner.name << endl;
        }
    }
}

int main() {
    const int N = 3;
    const float minBal = 3.5;
    Bank_Account acc[N];

    for (int i = 0; i <N; i++) {
        acc[i].id = i;
        
        cout << "Please enter the name of the owner: ";
        cin >> acc[i].owner.name;
        
        cout << "Please enter the national code of the owner: ";
        cin >> acc[i].owner.national_code;
        
        cout << "Please enter the educational degree of the owner: ";
        cin >> acc[i].owner.education;

        cout << "How much money do you have? ";
        cin >> acc[i].balance;

        cout << endl;
    }

    sortInfo(acc, N);

    for (int i = 0; i <N; i++) {
        acc[i].id = i;
        
        cout << "Name: " << acc[i].owner.name;
        
        cout << " National code: " << acc[i].owner.national_code;
        
        cout << " Educational degree: " << acc[i].owner.education;

        cout << " Money: " << acc[i].balance << endl;
    }

    findBelow(acc, N, minBal);
}