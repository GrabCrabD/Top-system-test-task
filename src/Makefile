CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -ftest-coverage
LIBS = -lgtest -lgtest_main -pthread

all: shapes.a test

shapes.a: shapes.o
	ar rcs shapes.a shapes.o

shapes.o: shapes.cpp shapes.hpp
	$(CXX) $(CXXFLAGS) -c shapes.cpp -o shapes.o

test:
	$(CXX) $(CXXFLAGS) shapes_tests.cpp $(LIBS) -o test
	./test

leaks_test:
	$(CXX) $(CXXFLAGS) shapes_tests.cpp $(LIBS) -o test
	leaks -atExit -- ./test

shapes:
	$(CXX) $(CXXFLAGS) shapes.cpp -o shapes
	./shapes

clean:
	rm -rf ./shapes ./test *.o *.gcov *.gcno *.gcda *.a