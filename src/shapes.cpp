#include "shapes.hpp"

int main() {
  // Создаем объекты различных фигур
  Shape* circle = new Circle(5.0);
  Shape* square = new Square(4.0);
  Shape* triangle = new Triangle(3.0, 4.0, 5.0);

  // Выводим фигуры на экран
  circle->draw();
  square->draw();
  triangle->draw();

  // Освобождаем память, вызывая деструкторы
  delete circle;
  delete square;
  delete triangle;

  return 0;
}