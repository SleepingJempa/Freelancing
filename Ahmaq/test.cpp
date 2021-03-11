#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

class Root {
public:
    void play() {}
    virtual void eat() = 0;
    void live() { play(); eat(); }
private:
    int data;
    void sleep() {}
};

class Class1 : public Root {
public:
    void eat() {}
};

class Class2 : public Root {
public:
    int play() { return 0; }
    int play(int x) { return x + data; }
    int sleep() {}
protected:
    void live() {}
};


int main() {
    Class1 c;
    Root* rp = &c;
    rp->eat();
    Class2* cp = &c;
    cp->eat();
    cp = new Class2();
    cp->eat();
}

// h1 h2 g1 g2 f1 g5 h4 h5