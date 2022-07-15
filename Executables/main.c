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
    s21_set_scale(&val1, 28);
    val1.LOWBIT = UINT_MAX;
    val1.MEDBIT = UINT_MAX;
    val1.HIGHBIT = UINT_MAX;
//    val1.bits[3] = 0;
//    s21_set_sign(&val1);
    //
    s21_set_scale(&val2, 28);
    val2.LOWBIT = UINT_MAX;
    val2.MEDBIT = UINT_MAX;
    val2.HIGHBIT = UINT_MAX;
//    val2.bits[3] = 0;
//    s21_set_sign(&val2);
//    s21_print_dec_long(res);
    printf("..\n");
    s21_print_decimal(val1);
    printf("*\n");
    s21_print_decimal(val2);
// 123 -> mul ten by 27 is overflow, 1 -> mul ten by 29 is overflow
    int ex_code = s21_mul(val1, val2, &res);
//    int ex_code = s21_div_ten(&val1, 99999);
    printf("=\n");
//    s21_print_dec_long(res);
    s21_print_decimal(res);
//    s21_print_decimal(val1);
    printf("ex_code %d\n", ex_code);

    return 0;
}

