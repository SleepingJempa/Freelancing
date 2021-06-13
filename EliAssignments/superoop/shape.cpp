#include <iostream>
using namespace std;

class Shape {
private:
    double width;
    double height;
public:
    Shape(double width, double height) : width(width), height(height) {};
    double getWidth() { return width; }
    double getHeight() { return height; }
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : Shape(width, height) {}
    double getArea() { return getWidth() * getHeight(); }
    double getPerimeter() { return 2 * (getWidth() + getHeight()); }
};

// Equal Sides
class Triangle : public Shape {
public:
    Triangle(double width) : Shape(width, width * sqrt(3) / 2) {}
    double getArea() { return getWidth() * getHeight(); }
    double getPerimeter() { return 3 * getWidth(); }
};
