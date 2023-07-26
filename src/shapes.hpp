#include <cmath>
#include <iostream>

using namespace std;

class Shape {
 public:
  virtual void draw() const = 0;
  virtual ~Shape() {}
};

class Circle : public Shape {
 private:
  double radius;

 public:
  Circle(double r) : radius(r) {}
  ~Circle() override {}
  void draw() const override {
    cout << "Drawing a circle with radius " << radius << endl;
  }
};

class Square : public Shape {
 private:
  double side;

 public:
  Square(double s) : side(s) {}
  ~Square() override {}
  void draw() const override {
    cout << "Drawing a square with side " << side << endl;
  }
};

// Класс для треугольника
class Triangle : public Shape {
 private:
  double side1, side2, side3;

 public:
  Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
  ~Triangle() override {}
  void draw() const override {
    cout << "Drawing a triangle with sides " << side1 << ", " << side2 << ", "
         << side3 << endl;
  }
};
