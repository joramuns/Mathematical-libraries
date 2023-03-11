all: style statanalyze vg

build:
	g++ -g main.cc s21_matrix_oop.cc

test: build
	./a.out

vg: build
	valgrind --trace-children=yes --track-fds=all  --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

style:
	clang-format -style=Google -n *.cc
	clang-format -style=Google -n *.h

statanalyze:
	cppcheck --enable=all --suppress=missingIncludeSystem .
