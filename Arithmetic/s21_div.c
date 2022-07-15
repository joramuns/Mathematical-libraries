//
//  s21_div.c
//  Decimal
//


#include <stdio.h>
#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    s21_decimal dividend, divisor, one, res_dec;
    s21_dec_copy(value_1, &dividend);
    s21_dec_zero(result);
    s21_dec_zero(&res_dec);
    int i = 4;

    while (i >= 0) {
        s21_dec_copy(value_2, &divisor);
        s21_left_shift_bit(&divisor, i);
        if (s21_is_greater(dividend, divisor)) {
            s21_dec_zero(&value_1);
            s21_sub(dividend, divisor, &value_1);
            s21_dec_copy(value_1, &dividend);
            //
            s21_dec_zero(&one);
            one.bits[0] = 1;
            s21_left_shift_bit(&one, i);
            s21_dec_zero(&res_dec);
            s21_add(*result, one, &res_dec);
            s21_dec_copy(res_dec, result);
        }
        i--;
    }

    return ex_code;
}
