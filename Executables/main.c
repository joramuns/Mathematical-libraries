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
    test.LOWBIT = 17;
    test.MEDBIT = 128;
    test.HIGHBIT = 999999;
    test.bits[3] = 0;
    s21_print_decimal(test);
//    s21_print_dec_long(test);
//    printf("Sign = %d\n", s21_get_sign(test));
//    s21_set_bit(&test, 120);
//    s21_set_bit(&test, 119);
//    s21_set_bit(&test, 118);
//    s21_set_bit(&test, 117);
    s21_set_bit(&test, 116);
    s21_set_bit(&test, 115);
    s21_set_bit(&test, 114);
//    s21_set_bit(&test, 113);
    s21_print_decimal(test);
    printf("Scale = %d\n", s21_get_scale(test));
    return 0;
}
