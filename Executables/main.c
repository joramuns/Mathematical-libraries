//
//  main.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    //
    s21_decimal res, val1, val2;
    s21_dec_zero(&res);
    //
    val1.LOWBIT = 123;
    val1.MEDBIT = 432;
    val1.HIGHBIT = 0;
    val1.bits[3] = 0;
    s21_set_sign(&val1);
    //
    val2.LOWBIT = 123000;
    val2.MEDBIT = 798;
    val2.HIGHBIT = 0;
    val2.bits[3] = 0;
//    s21_set_sign(&val2);
    s21_print_dec_long(res);
    printf("..\n");
    s21_print_decimal(val1);
    printf("-\n");
    s21_print_decimal(val2);
    s21_add(val1, val2, &res);
    printf("=\n");
//    s21_print_dec_long(res);
    s21_print_decimal(res);

    return 0;
}
