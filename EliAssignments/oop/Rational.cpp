#include <iostream>

using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;
public:
    Rational(int numerator, int denominator);
    void showFraction();
    void showDecimal();
    int n() { return numerator; }
    int d() { return denominator; }
    Rational negate() { return Rational(-numerator, denominator); }
    Rational inverse() { return Rational(denominator, numerator); }
    static Rational addition(Rational a, Rational b);
    static Rational substraction(Rational a, Rational b);
    static Rational multiply(Rational a, Rational b);
    static Rational division(Rational a, Rational b);
};

Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw "Division by zero.";
    }
}

void Rational::showFraction() {
    cout << "[F] " << numerator << " / " << denominator << endl;
}

void Rational::showDecimal() {
    cout << "[D] " << (float)(numerator) / (float)(denominator) << endl;
}

static Rational addition(Rational a, Rational b) {
    return Rational(a.n() * b.d() + b.n() * a.d(), a.d() * b.d());
}

static Rational substraction(Rational a, Rational b) {
    return addition(a, b.negate());
}

static Rational multiply(Rational a, Rational b) {
    return Rational(a.n() * b.n(), a.d() * b.d());
}

static Rational division(Rational a, Rational b) {
    return multiply(a, b.inverse());
}


int main() {
    Rational one_fifth(1, 5);
    Rational three_seventh(3, 7);

    one_fifth.showDecimal();
    one_fifth.showFraction();

    three_seventh.showDecimal();
    three_seventh.showFraction();

    Rational add = addition(one_fifth, three_seventh);
    add.showDecimal();
    add.showFraction();

    Rational sub = substraction(one_fifth, three_seventh);
    sub.showDecimal();
    sub.showFraction();

    Rational mul = multiply(one_fifth, three_seventh);
    mul.showDecimal();
    mul.showFraction();

    Rational div = division(one_fifth, three_seventh);
    div.showDecimal();
    div.showFraction();
}