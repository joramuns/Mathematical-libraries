//
//  main.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    s21_decimal test;
    test.LOWBIT = 2;
    test.MEDBIT = 3;
    test.HIGHBIT = 0;
    test.bits[3] = 0;
    s21_print_dec_long(test);
    printf("%d\n", s21_get_bit(test.LOWBIT, 3));
    s21_shift_bit(&test, 64);
//    s21_set_bit(&test, 32);
    s21_print_dec_long(test);
    s21_print_decimal(test);
    return 0;
}
