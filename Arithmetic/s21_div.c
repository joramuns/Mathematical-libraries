//
//  s21_div.c
//  Decimal
//


#include <stdio.h>
#include "../s21_decimal.h"

s21_decimal s21_dec_and(s21_decimal value_1, s21_decimal value_2) {
    s21_decimal result;
    s21_dec_zero(&result);

    for (int i = 0; i < 3; i++) {
        result.bits[i] = value_1.bits[i] & value_2.bits[i];
    }

    return result;
}

s21_decimal s21_dec_or(s21_decimal value_1, s21_decimal value_2) {
    s21_decimal result;
    s21_dec_zero(&result);

    for (int i = 0; i < 3; i++) {
        result.bits[i] = value_1.bits[i] | value_2.bits[i];
    }

    return result;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    s21_decimal remainder, one, res_dec;
    s21_dec_zero(result);
    s21_dec_zero(&remainder);

    for (int i = 95; i >= 0; i--) {
        s21_left_shift_bit(result, 1);
        s21_left_shift_bit(&remainder, 1);
        one.bits[0] = 1;
        s21_dec_zero(&res_dec);

        s21_left_shift_bit(&one, i);
        res_dec = s21_dec_and(value_1, one);
        s21_right_shift_bit(&res_dec, i);

        remainder = s21_dec_or(remainder, res_dec);

        if (s21_is_greater_or_equal(remainder, value_2)) {
            s21_dec_copy(remainder, &res_dec);
            s21_dec_zero(&remainder);
            s21_sub(res_dec, value_2, &remainder);
            one.bits[0] = 1;
            *result = s21_dec_or(*result, one);
        }
    }

    return ex_code;
}
