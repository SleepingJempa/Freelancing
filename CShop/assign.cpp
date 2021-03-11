#include <iostream>

using namespace std;

typedef struct Account {
    string id;
    string name;
    int balance;
    string address;
} Account;

const int N = 1000;
int n = 0;
Account acc[N];

void addAccount(string id, string name, int balance, string address);
void removeAccount(string id);
int getSum();
void showAccountInfo(Account account);
void showAll();

int main() {
    int cmd;

    while(true) {
        cout << "Store command line" << endl;
        cout << "1. Add an account" << endl;
        cout << "2. Remove an account" << endl;
        cout << "3. Sum of all account" << endl;
        cout << "4. Show all accounts Info" << endl;
        cout << "5. Exit" << endl;

        cin >> cmd;

        if (cmd == 5) break;

        if (cmd == 1) {
            cout << "Add Method" << endl;
            string id;
            string name;
            int balance;
            string address;

            cout << "Enter the id: " << endl;
            cin >> id;
            cout << "Enter the name: " << endl;
            cin >> name;
            cout << "Enter the balance: " << endl;
            cin >> balance;
            cout << "Enter the address: " << endl;
            cin >> address;

            addAccount(id, name, balance, address);
        }

        if (cmd == 2) {
            string id;

            cout << "Remove Method" << endl;
            cout << "Enter the id: " << endl;
            cin >> id;

            removeAccount(id);
        }

        if (cmd == 3) {
            cout << "Sum of all accounts is equal to: " << getSum() << endl;
        }

        if (cmd == 4) {
            cout << "All accounts info" << endl;
            showAll();
        }

        
        cout << "===========" << endl;
    }
}

void addAccount(string id, string name, int balance, string address) {
    acc[n].id = id;
    acc[n].name = name;
    acc[n].balance = balance;
    acc[n].address = address;

    n++;
}

void removeAccount(string id) {
    for(int i=0; i<n; i++) {
        if (acc[i].id == id) {
            while(i+1 < n) {
                acc[i] = acc[i+1];
                i++;
            }
            n--;
            break;
        }
    }
}

int getSum() {
    cout << "===[ All Accounts Sum ]===" << endl;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += acc[i].balance;
    }
    return sum;
    cout << "===========" << endl;
}

void showAccountInfo(Account account) {
    cout << "===[ Account Info ]===" << endl;
    cout << "ID:\t\t\t" << account.id << endl;
    cout << "Name:\t\t\t" << account.name << endl;
    cout << "Balance:\t\t" << account.balance << endl;
    cout << "Address:\t\t" << account.address << endl;
    cout << "===========" << endl;
}

void showAll() {
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        showAccountInfo(acc[i]);
    }
}
