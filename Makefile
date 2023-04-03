CC=g++
GCOV=--coverage
GCOV_FLAG=
STATLIB_BUILD=ar rcs
FLAGS=-g -O0 -Wall -Werror -Wextra -std=c++17 -pedantic 
GTEST_FLAGS=$(shell pkg-config --libs gtest)
SOURCE=s21_matrix_oop.cc
TESTS_SOURCE=$(shell find ../tests -name '*.cc')
OBJ=$(SOURCE:.cc=.o)
TESTS_OBJ=$(TESTS_SOURCE:.cc=.o)

all: style statanalyze vg

%.o: %.cc
	$(CC) -c $< -o $@ $(FLAGS) $(GTEST_FLAGS)

s21_matrix_oop.a: $(OBJ)
	$(STATLIB_BUILD) $@ $(OBJ)
	ranlib $@

mtest: s21_matrix_oop.a
	$(CC) -g -c main.cc
	$(CC) -o a.out main.o $<
	./a.out

test: s21_matrix_oop.a $(TESTS_OBJ)
	$(CC) $(TESTS_OBJ) $< -o $@ $(FLAGS) $(GTEST_FLAGS)
	./test

vg: test
	valgrind --trace-children=yes --track-fds=all  --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

gcov_report:FLAGS+=$(GCOV)
gcov_report: clean test
	lcov -t "S21 Matrix OOP" -o coverage.info -c -d . --rc lcov_branch_coverage=0 --no-external
	genhtml -o report coverage.info --rc lcov_branc_coverage=0
	open ./report/index.html

style:
	clang-format -style=Google -n *.cc
	clang-format -style=Google -n *.h

statanalyze:
	cppcheck --enable=all --suppress=missingIncludeSystem .

clean:
	-@rm -rf *.o *.gcno *.gcda *.info report/
	@echo "[Clean]"

fclean: clean
	-@rm -f ../tests/*.gcno ../tests/*.gcda ../tests/*.o *.a test
	@echo "[Full clean]"
