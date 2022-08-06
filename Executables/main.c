//
//  main.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    int ex_code = 0;
    s21_decimal res, val1, val2;
    s21_dec_zero(&res);

    val1.LOWBIT = 0xFFFFFFFF;
    val1.MEDBIT = 0xFFFFFFFF;
    val1.HIGHBIT = 0xFFFFFFFF;
    val1.bits[3] = 0;
    s21_set_scale(&val1, 1);

    val2.LOWBIT = 1;
    val2.MEDBIT = 0;
    val2.HIGHBIT = 0;
    val2.bits[3] = 0;
    s21_set_scale(&val2, 2);

//    s21_set_sign(&val1);
//    s21_set_sign(&val2);

    s21_print_decimal(val1);
    printf("/\n");
    s21_print_decimal(val2);

    ex_code = s21_div(val1, val2, &res);

    printf("=\n");
    s21_print_decimal(res);

    return ex_code;
}
