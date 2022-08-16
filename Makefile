CC=gcc -g
GCOV=gcc --coverage
CFLAGS=-c -std=c11 -pedantic -Wall -Werror -Wextra
OFLAGS=-o -std=c11 -pedantic -Wall -Werror -Wextra
CFLAGSan=-std=c11 -pedantic -Wall -Werror -Wextra -fsanitize=address -c
OFLAGSan=-std=c11 -pedantic -Wall -Werror -Wextra -fsanitize=address -o
LFLAG=-lcheck
FUNCTIONS=Supportive/*.c Core/*.c Simple/*.c Specific/*.c
TESTS=Tests/*.c

all:
	$(MAKE) gcov_report

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info test sanit mtest

clean_o:
	rm -rf *.o

mtest: s21_matrix.a manual_test.o
	$(CC) $(OFLAGS) mtest *.o s21_matrix.a
	rm -rf *.o
	./mtest

manual_test.o:
	$(CC) $(CFLAGS) Executables/manual_test.c

test: s21_matrix.a check_main.o
	-$(CC) $(OFLAGS) test *.o s21_matrix.a `pkg-config --cflags --libs check`
	rm -rf *.o
	./test

sanit: sanit_s21_matrix.a sanit_check_main.o
	$(CC) $(OFLAGSan) sanit *.o s21_matrix.a `pkg-config --cflags --libs check`
	rm -rf check_main.o
	./sanit

sanit_check_main.o:
	$(CC) $(CFLAGSan) Executables/check_main.c $(TESTS)

sanit_s21_matrix.a:
	$(CC) $(CFLAGSan) $(FUNCTIONS)
	ar -rc s21_matrix.a *.o
	ranlib s21_matrix.a
	$(MAKE) clean_o

gcov_report: gcov-s21_matrix.a gcov-check_main.o
	$(GCOV) $(OFLAGS) test *.o s21_matrix.a `pkg-config --cflags --libs check`
	./test
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=0
	genhtml -o report test.info --rc lcov_branch_coverage=0
	$(MAKE) clean

gcov-s21_matrix.a:
	$(GCOV) $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_matrix.a *.o
	ranlib s21_matrix.a
	$(MAKE) clean_o

s21_matrix.a:
	$(CC) $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_matrix.a *.o
	ranlib s21_matrix.a
	$(MAKE) clean_o

check_main.o: clean_o
	$(CC) $(CFLAGS) Executables/check_main.c $(TESTS)

gcov-check_main.o:
	$(GCOV) $(CFLAGS) Executables/check_main.c $(TESTS)

debug:
	$(CC) -g $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_matrix.a *.o
	ranlib s21_matrix.a
	$(CC) -g $(CFLAGS) Executables/check_main.c $(TESTS)
	-$(CC) -g $(OFLAGS) test *.o s21_matrix.a `pkg-config --cflags --libs check`
	./test

rebuild:
	$(MAKE) clean
	$(MAKE) s21_matrix.a


