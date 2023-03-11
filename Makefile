all: vg

build:
	g++ -g main.cc s21_matrix_oop.cc

vg: build
	valgrind --trace-children=yes --track-fds=all  --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
