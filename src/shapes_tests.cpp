#include <gtest/gtest.h>

#include <stdexcept>

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
  testing::internal::CaptureStdout();
  square->draw();
  std::string output = testing::internal::GetCapturedStdout();
  delete square;
  EXPECT_EQ(output, "Drawing a square with side 4\n");
}

TEST(ShapesTest, Constructor3) {
  Shape* triangle = new Triangle(3.0, 4.0, 5.0);
  testing::internal::CaptureStdout();
  triangle->draw();
  std::string output = testing::internal::GetCapturedStdout();
  delete triangle;
  EXPECT_EQ(output, "Drawing a triangle with sides 3, 4, 5\n");
}

TEST(ShapesTest, Constructor1_Error) {
  Shape* circle = nullptr;
  ASSERT_THROW(circle = new Circle(-5.0), std::invalid_argument);
  delete circle;
}

TEST(ShapesTest, Constructor2_Error) {
  Shape* square = nullptr;
  ASSERT_THROW(square = new Square(0), std::invalid_argument);
  ASSERT_THROW(square = new Square(-4.0), std::invalid_argument);
  delete square;
}

TEST(ShapesTest, Constructor3_Error) {
  Shape* triangle = nullptr;
  ASSERT_THROW(triangle = new Triangle(3.0, 4.0, 8.0), std::invalid_argument);
  ASSERT_THROW(triangle = new Triangle(3.0, -4.0, 5.0), std::invalid_argument);
  ASSERT_THROW(triangle = new Triangle(0.0, 4.0, 5.0), std::invalid_argument);
  delete triangle;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}