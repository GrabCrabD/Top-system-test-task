#include <gtest/gtest.h>

#include "shapes.hpp"

TEST(ShapesTest, Constructor1) {
  Shape* circle = new Circle(5.0);
  testing::internal::CaptureStdout();  // Захват вывода на экран
  circle->draw();
  std::string output = testing::internal::GetCapturedStdout();
  delete circle;  // удалить объект, чтобы избежать утечек памяти
  EXPECT_EQ(output, "Drawing a circle with radius 5\n");
}
TEST(ShapesTest, Constructor2) {
  Shape* square = new Square(4.0);
  testing::internal::CaptureStdout();  // Захват вывода на экран
  square->draw();
  std::string output = testing::internal::GetCapturedStdout();
  delete square;  // удалить объект, чтобы избежать утечек памяти
  EXPECT_EQ(output, "Drawing a square with side 4\n");
}

TEST(ShapesTest, Constructor3) {
  Shape* triangle = new Triangle(3.0, 4.0, 5.0);
  testing::internal::CaptureStdout();  // Захват вывода на экран
  triangle->draw();
  std::string output = testing::internal::GetCapturedStdout();
  delete triangle;  // удалить объект, чтобы избежать утечек памяти
  EXPECT_EQ(output, "Drawing a triangle with sides 3, 4, 5\n");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}