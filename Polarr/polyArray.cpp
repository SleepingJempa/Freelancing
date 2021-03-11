#include <iostream>
#include <vector>

using namespace std;

// The number of exponent saved in a Polynomial class
int N = 1000;

// Constants for command line tool switch case
const int EXIT = -1;
const int ADD_TERM = 0;
const int REMOVE_TERM = 1;
const int SEARCH_TERM = 2;
const int ADD_POLY = 3;
const int SUB_POLY = 4;
const int MULT_POLY = 5;
const int PRINT_POLY = 6;

/**
 * Term Class
 *  Contain an exponent and a coefficient for one term of an polynomial.
 */
class Term {
public:
    int e;
    float c;
    Term(int exponent, float coefficient) : e(exponent), c(coefficient) {};
friend class Polynomial;
};

/**
 * Polynomial Class
 *  Stores a polynomial in array form as many Term objects.
 */
class Polynomial {
    public:
    vector<Term> terms;
    Polynomial(int n = N);
    // NaN stands for Not a Number
    const static int NaN = INT32_MIN;
    bool addTerm(int e, int c);
    bool removeTerm(int e);
    float searchItem(int e);
    void addPoly(Polynomial other);
    void subPoly(Polynomial other);
    void multPoly(Polynomial other);
};

/**
 * Print Polynomial method
 * @param p: reference to a polynomial which wanted to be printed on console.
 */
void printPolynomial(const Polynomial& p);

int main() {
    // Two major polynomial for the program
    vector<Polynomial> p(2);

    /**
     * Command Line tool
     *  Exit with pressing Ctrl+Z after completing operations or enter -1 at the same position.
     * @param i: the index of polynomial which will be used in operations
     * @param cmd: the index of the operation which was described in the assignment source.
     * @param e: the exponent if is provided
     * @param c: the coefficient if is provided
     */
    int i;
    int cmd;
    int e, c;

    while( cin >> i ) {
        if (i == EXIT) break;
        cin >> cmd;
        switch(cmd) {
            case ADD_TERM:
                cin >> e >> c;
                p[i].addTerm(e, c);
                break;
            case REMOVE_TERM:
                cin >> e;
                p[i].removeTerm(e);
                break;
            case SEARCH_TERM:
                cin >> e;
                cout << p[i].searchItem(e) << endl;
                break;
            case ADD_POLY:
                p[i].addPoly(p[1-i]);
                break;
            case SUB_POLY:
                p[i].subPoly(p[1-i]);
                break;
            case MULT_POLY:
                p[i].multPoly(p[1-i]);
                break;
            case PRINT_POLY:
                printPolynomial(p[i]);
                break;
            default:
                // Wrong Action will not change or print anything.
                break;
        }
    }
}

void printPolynomial(const Polynomial& p) {
    bool notEmpty = false;

    for(int i = N-1; i >= 0; i--) {
        // Zero terms are hidden
        if (p.terms[i].c == 0) continue;
        // If a term has non-zero coefficient, so the polynomial is not empty
        notEmpty = true;
        cout << p.terms[i].c;
        // No x^ symbol for constant part of the polynomial (x^0)
        if (i) cout << "x^" << i;
        cout << '+';
    }
    if (notEmpty) {
        // Eliminate the last '+' character and go to the next line in console.
        cout << "\b \n";
    } else {
        // If polynomial is empty
        cout << 0 << endl;
    }
}

/**
 * Instantiate a new Polynomial
 * @param n: the number of terms will be stored. default = N
 */
Polynomial::Polynomial(int n) {
    terms.resize(n, Term(0, 0));
    // Setting the exponent of the i-th term to the i.
    for(int i = 0; i < n; i++) {
        terms[i].e = i;
    }
}

/**
 * Add a some coefficient to the corresponding term of the polynomial.
 * @param e: the exponent
 * @param c: the coefficient
 */
bool Polynomial::addTerm(int e, int c) {
    // If 
    if (this->searchItem(e) == NaN) return false;
    terms[e].c += c;
    return true;
}

/**
 * Remove the term with desired exponent.
 * @param e: the desired exponent
 * @return true if the term was removed, otherwise false because the term with that exponent does not exist in range.
 */
bool Polynomial::removeTerm(int e) {
    // If the exponent is not in range of the polynomial size return false.
    if (this->searchItem(e) == NaN) return false;
    // Remove the term and return true.
    terms[e].c = 0;
    return true;
}

/**
 * Look for a term with desired exponent.
 * @param e: the exponent
 * @return the coefficient of the term if that exist, otherwise NaN.
 */
float Polynomial::searchItem(int e) {
    if (e >= N || e < 0) return NaN;
    return terms[e].c;
}

/**
 * Add a polynomial to this polynomial.
 * @param other: another polynomial
 */
void Polynomial::addPoly(Polynomial other) {
    for(Term term : other.terms) {
        terms[term.e].c += term.c;
    }
}

/**
 * Subtract a polynomial from this polynomial.
 * @param other: another polynomial
 */
void Polynomial::subPoly(Polynomial other) {
    for(Term term : other.terms) {
        terms[term.e].c -= term.c;
    }
}

/**
 * Polynomial Multiplication, but stores the result in the caller object (this).
 * @param other: another polynomial
 */
void Polynomial::multPoly(Polynomial other) {
    // Initialization of result
    Polynomial result(N);

    // Multiplication operation
    for(Term myTerm : terms) {
        for(Term otherTerm : other.terms) {
            int e = myTerm.e + otherTerm.e;
            int c = myTerm.c * otherTerm.c;
            if (e >= N || e < 0) continue;
            result.addTerm(e, c);
        }
    }

    // String the result to the caller object
    for(Term term : result.terms) {
        terms[term.e].c = term.c;
    }
}

