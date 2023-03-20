all: style statanalyze vg

build:
	g++ -g -c s21_matrix_oop.cc

test: clean build
	g++ -g -c main.cc
	g++ -o a.out *.o
	./a.out

gtest: clean build
	g++ -g -c tests_matrix_oop.cc
	g++ -o a.out *.o -lgtest
	./a.out

vg: build
	valgrind --trace-children=yes --track-fds=all  --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

style:
	clang-format -style=Google -n *.cc
	clang-format -style=Google -n *.h

statanalyze:
	cppcheck --enable=all --suppress=missingIncludeSystem .

clean:
	rm *.o
