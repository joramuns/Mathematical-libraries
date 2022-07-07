//
//  s21_mul_ten.c
//  Decimal
//

#include "s21_decimal.h"

int s21_mul_ten(s21_decimal *value, int scale) {
    int sign = 0, ex_code = 0;
    s21_decimal mul_2, mul_8, temp;

    if (s21_get_sign(*value)) {
        s21_zero_bit(value, 127);
        sign = 1;
    }
    while (scale-- > 0 && !ex_code) {
        if (s21_last_non_zero(*value) < 93) {
//            s21_dec_copy(*value, &mul_2);
//            s21_dec_copy(*value, &mul_8);
//            s21_dec_zero(value);
//            s21_left_shift_bit(&mul_2, 1);
//            s21_left_shift_bit(&mul_8, 3);
//            s21_add(mul_2, mul_8, value);
//            (n << 2 + n) << 1 ?
            s21_dec_copy(*value, &temp);
            s21_dec_copy(*value, &mul_2);
            s21_dec_zero(value);
            s21_left_shift_bit(&temp, 2);
            s21_add(temp, mul_2, value);
            s21_left_shift_bit(value, 1);
        } else {
            ex_code = 1;
            s21_set_inf(value);
        }
    }
    if (sign) {
        s21_set_sign(value);
    }

    return ex_code;
}
