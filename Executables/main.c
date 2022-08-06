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
    s21_set_scale(&val1, 0);
//
    val2.LOWBIT = 11;
    val2.MEDBIT = 0;
    val2.HIGHBIT = 0;
    val2.bits[3] = 0;
    s21_set_scale(&val2, 1);

//    s21_set_sign(&val1);
    s21_set_sign(&val2);

//    s21_print_dec_long(res);
//    printf("..\n");
//    ex_code = s21_scale_equalize(&val1, &val2);
    s21_print_decimal(val1);
    printf("/\n");
    s21_print_decimal(val2);
// 123 -> mul ten by 27 is overflow, 1 -> mul ten by 29 is overflow
    ex_code = s21_mul(val1, val2, &res);
//    ex_code = s21_div_ten(&val1);
    printf("=\n");
//    s21_print_dec_long(res);
    s21_print_decimal(res);
//    s21_print_decimal(val1);

    return ex_code;
}
