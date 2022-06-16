CC=gcc
GCOV=gcc --coverage
CFLAGS=-std=c11 -Wall -Werror -Wextra -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -o
CFLAGSan=-std=c11 -Wall -Werror -Wextra -fsanitize=address -c
OFLAGSan=-std=c11 -Wall -Werror -Wextra -fsanitize=address -o
LFLAG=-lcheck
FUNCTIONS=s21_abs.c s21_pow.c s21_log.c s21_sqrt.c s21_fabs.c s21_factorial.c s21_exp.c s21_sin.c s21_cos.c s21_tan.c s21_atan.c s21_asin.c s21_acos.c s21_ceil.c s21_floor.c s21_fmod.c
TESTS=tests/*.c

all:
	$(MAKE) gcov_report

clean:
	rm -rf *.o *.so *.gcda *.a *.gcno *.info test sanit

clean_o:
	rm -rf *.o

test: s21_math.a main.o
	-$(CC) $(OFLAGS) test *.o s21_math.a `pkg-config --cflags --libs check`
	rm -rf *.o
	./test

sanit: sanit_s21_math.a sanit_main.o
	$(CC) $(OFLAGSan) sanit *.o s21_math.a `pkg-config --cflags --libs check`
	rm -rf main.o
	./sanit

sanit_main.o:
	$(CC) $(CFLAGSan) main.c $(TESTS)

sanit_s21_math.a:
	$(CC) $(CFLAGSan) $(FUNCTIONS)
	ar -rc s21_math.a *.o
	ranlib s21_math.a
	$(MAKE) clean_o

gcov_report: gcov-s21_math.a gcov-main.o
	$(GCOV) $(OFLAGS) test *.o s21_math.a `pkg-config --cflags --libs check`
	./test
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1
	$(MAKE) clean

gcov-s21_math.a:
	$(GCOV) $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_math.a *.o
	ranlib s21_math.a
	$(MAKE) clean_o

s21_math.a:
	$(CC) $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_math.a *.o
	ranlib s21_math.a
	$(MAKE) clean_o

main.o: clean_o
	$(CC) $(CFLAGS) main.c $(TESTS)

gcov-main.o:
	$(GCOV) $(CFLAGS) main.c $(TESTS)

debug:
	$(CC) -g $(CFLAGS) $(FUNCTIONS)
	ar -rc s21_math.a *.o
	ranlib s21_math.a
	$(CC) -g $(CFLAGS) main.c $(TESTS)
	-$(CC) -g $(OFLAGS) test *.o s21_math.a `pkg-config --cflags --libs check`
	./test

rebuild:
	$(MAKE) clean
	$(MAKE) s21_math.a


