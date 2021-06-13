#include <iostream>

using namespace std;

class MyString
{
private:
    string data;
public:
    MyString(string data) : data(data) {};
    string getData() { return data; }
    void setData(string data) { this->data = data; }
    bool STRCMP(MyString other);
    int STRLEN() { return data.length(); }
    void STRCOPY(MyString other) { setData(other.getData()); }
    void STRCAT(MyString other) { setData(data + other.getData()); }
    void print(char end='\0') { cout << data; cout << end;}
};

bool MyString::STRCMP(MyString other) {
    if (STRLEN() != other.STRLEN()) return false;

    for(int i = 0; i < STRLEN(); i++) {
        if (data[i] != other.getData()[i]) return false;
    }

    return true;
}


int main() {
    MyString ms1("elham");
    MyString ms2("asadi");
    MyString ms3("elham");
    MyString ms4("elha");

    ms1.print(' '); //  VVVVVV
    ms2.print('\n'); // elham asadi

    cout << ms1.STRCMP(ms2) << endl; // elham == asadi => 0
    cout << ms1.STRCMP(ms3) << endl; // elham == elham => 1
    cout << ms1.STRCMP(ms4) << endl; // elham == elha => 0

    cout << ms1.STRLEN() << endl; // elham => 5
    cout << ms4.STRLEN() << endl; // elha => 4

    ms4.STRCOPY(ms3);
    ms4.print('\n'); // elham

    ms1.STRCAT(ms2);
    ms1.print('\n'); // => elhamasadi
}