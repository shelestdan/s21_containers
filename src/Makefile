CPPC = gcc
CPPFLAGS = -Wall -Wextra -Werror -std=c++17
LIBS = -lstdc++ -lgtest
SOURSE_INCLUDE = includes
TEST_FILES = tests/tests.cpp

all: test run_test

test:
	${CPPC} ${CPPFLAGS} ${TEST_FILES} -I${SOURSE_INCLUDE} ${LIBS} -o test.out

run_test:
	./test.out

leaks: test
	leaks -atExit -- ./test.out

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n includes/*/*.h tests/tests.cpp

clang-fix:
	cp ../materials/linters/.clang-format .
	clang-format -i includes/*/*.h tests/tests.cpp

clean:
	rm -f *.a
	rm -f *.o
	rm -f *.out
	rm -f test
	rm -f .clang-format