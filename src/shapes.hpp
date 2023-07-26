#include <cmath>
#include <iostream>
#include <stdexcept>

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
  Circle(double r) : radius(r) {
    if (radius <= 0) {
      throw invalid_argument("Circle radius must be greater than zero.");
    }
  }
  ~Circle() override {}
  void draw() const override {
    cout << "Drawing a circle with radius " << radius << endl;
  }
};

class Square : public Shape {
 private:
  double side;

 public:
  Square(double s) : side(s) {
    if (side <= 0) {
      throw invalid_argument("Square side length must be greater than zero.");
    }
  }
  ~Square() override {}
  void draw() const override {
    cout << "Drawing a square with side " << side << endl;
  }
};

class Triangle : public Shape {
 private:
  double side1, side2, side3;

 public:
  Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || side1 + side2 <= side3 ||
        side1 + side3 <= side2 || side2 + side3 <= side1) {
      throw invalid_argument(
          "Invalid sides for triangle. All sides must be greater than zero and "
          "satisfy the triangle inequality.");
    }
  }
  ~Triangle() override {}
  void draw() const override {
    cout << "Drawing a triangle with sides " << side1 << ", " << side2 << ", "
         << side3 << endl;
  }
};
