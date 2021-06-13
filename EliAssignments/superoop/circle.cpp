#include <iostream>
using namespace std;

const float PI = 3.1415926535;

class Circle {
private:
    float radius;
public:
    Circle(float radius) : radius(radius) {}
    float circumference() { return 2 * PI * radius; }
    float area() { return radius * radius * PI; }
};