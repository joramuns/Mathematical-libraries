CC=gcc -g
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o
CFLAGSan=-std=c11 -Wall -Werror -Wextra -fsanitize=address -c
OFLAGSan=-std=c11 -Wall -Werror -Wextra -fsanitize=address -o
LFLAG=-lcheck
FUNCTIONS=Extradecimal/*.c Supportive/*.c Arithmetic/*.c Comparative/*.c Convertational/*.c Other/*.c
TESTS=Executables/Tests/*.c

all:
	$(MAKE) gcov_report

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info test sanit

clean_o:
	rm -rf *.o

test: s21_decimal.a check_main.o
	-$(CC) $(OFLAGS) test *.o s21_decimal.a `pkg-config --cflags --libs check`
	rm -rf *.o
	./test

sanit: sanit_s21_decimal.a sanit_check_main.o
	$(CC) $(OFLAGSan) sanit *.o s21_decimal.a `pkg-config --cflags --libs check`
	rm -rf check_main.o
	./sanit

sanit_check_main.o:
	$(CC) $(CFLAGSan) Executables/check_main.c $(TESTS)

sanit_s21_decimal.a:
	$(CC) $(CFLAGSan) $(FUNCTIONS)
	ar -rc s21_decimal.a *.o
	ranlib s21_decimal.a
	$(MAKE) clean_o

gcov_report: gcov-s21_decimal.a gcov-check_main.o
	$(GCOV) $(OFLAGS) test *.o s21_decimal.a `pkg-config --cflags --libs check`
	./test
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1
	$(MAKE) clean

gcov-s21_decimal.a:
	$(GCOV) $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_decimal.a *.o
	ranlib s21_decimal.a
	$(MAKE) clean_o

s21_decimal.a:
	$(CC) $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_decimal.a *.o
	ranlib s21_decimal.a
	$(MAKE) clean_o

check_main.o: clean_o
	$(CC) $(CFLAGS) Executables/check_main.c $(TESTS)

gcov-check_main.o:
	$(GCOV) $(CFLAGS) Executables/check_main.c $(TESTS)

debug:
	$(CC) -g $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_decimal.a *.o
	ranlib s21_decimal.a
	$(CC) -g $(CFLAGS) Executables/check_main.c $(TESTS)
	-$(CC) -g $(OFLAGS) test *.o s21_decimal.a `pkg-config --cflags --libs check`
	./test

rebuild:
	$(MAKE) clean
	$(MAKE) s21_decimal.a


