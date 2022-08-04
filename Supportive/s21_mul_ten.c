//
//  s21_mul_ten.c
//  Decimal
//

#include "s21_decimal.h"

int s21_mul_ten(s21_decimal *value, int scale) {
    int sign = 0, ex_code = 0;
    s21_decimal mul_2, mul_8, mul_res;
    if (s21_get_sign(*value)) {
        s21_zero_bit(value, 127);
        sign = 1;
    }
    while (scale-- && !ex_code) {
        s21_dec_copy(*value, &mul_res);
        if (s21_last_non_zero(mul_res) < 93) {
            s21_dec_copy(mul_res, &mul_2);
            s21_dec_copy(mul_res, &mul_8);
            s21_dec_zero(&mul_res);
            s21_left_shift_bit(&mul_2, 1);
            s21_left_shift_bit(&mul_8, 3);
            ex_code = s21_add(mul_2, mul_8, &mul_res);
        } else {
            ex_code = 1;
        }
        if (!ex_code) {
            s21_dec_copy(mul_res, value);
        }
    }
    if (sign) {
        s21_set_sign(value);
    }

    return ex_code;
}

