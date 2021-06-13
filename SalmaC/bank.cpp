#include <iostream>

using namespace std;

class Account
{
private:
    int balance;
public:
    Account(int balance);
    void credit(int amount);
    void debt(int amount);
    int getBalance();
};

Account::Account(int balance)
{
    this->balance = balance;
}

void Account::credit(int amount){
    balance += amount;
}

void Account::debt(int amount){
    if (balance < amount){
        cout << "Debt amount exceeded account balance.\n";
        return;
    }
    balance -= amount;
}
int Account::getBalance(){
    return balance;
}



int main() {
    Account account1(200);
    account1.credit(50);
    cout << account1.getBalance();
    account1.debt(100);
    cout << account1.getBalance();
}