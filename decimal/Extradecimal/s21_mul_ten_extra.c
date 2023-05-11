//
//  s21_mul_ten_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 8/4/22.
//
#include "s21_decimal_extra.h"

int s21_mul_ten_extra(s21_decimal_extra *value, int scale) {
    int ex_code = 0;
    s21_decimal_extra mul_2 = INITDECEXTRA, mul_8 = INITDECEXTRA, mul_res = INITDECEXTRA;

    while (scale-- > 0 && !ex_code) {
        s21_dec_copy_extra(*value, &mul_res);
        if (s21_last_non_zero_extra(mul_res) < 189) {
            s21_dec_copy_extra(mul_res, &mul_2);
            s21_dec_copy_extra(mul_res, &mul_8);
            s21_dec_zero_extra(&mul_res);
            s21_left_shift_bit_extra(&mul_2, 1);
            s21_left_shift_bit_extra(&mul_8, 3);
            ex_code = s21_add_extra(mul_2, mul_8, &mul_res);
        } else {
            ex_code = 1;
        }
        if (!ex_code) {
            s21_dec_copy_extra(mul_res, value);
        }
    }

    return ex_code;
}

