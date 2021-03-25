#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

float val(char ch)
{
    return float(ch - '0');
}

int operator(char ch)
{
    if (ch == '+' ||
        ch == '-' ||
        ch == '*' ||
        ch == '/' ||
        ch == '^')
        return 1;
    return -1;
}

int operand(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return -1;
}

float evaluate(int a, int b, char op)
{
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a);
    else
        return INT_MIN;
}

float solvePostfix(string postfix)
{
    int a, b;
    stack<float> s;
    string::iterator it;

    for (int i = 0; i < postfix.size(); i++)
    {
        if (operator(postfix[i]) != -1)
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(evaluate(a, b, postfix[i]));
        }
        else if (operand(postfix[i]) > 0)
        {
            s.push(val(postfix[i]));
        }
    }
    
    return s.top();
}

int main()
{
    string post = "13*62-*532/+";
    cout << "Answer: " << solvePostfix(post);
}