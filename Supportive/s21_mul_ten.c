//
//  s21_mul_ten.c
//  Decimal
//

#include "s21_decimal.h"

void s21_mul_ten(s21_decimal *value, int scale) {
    int sign = 0;

    if (s21_get_sign(*value)) {
        s21_zero_bit(value, 127);
        sign = 1;
    }
    for (; scale > 0; scale--) {
        s21_decimal mul_2, mul_8;
        s21_dec_copy(*value, &mul_2);
        s21_dec_copy(*value, &mul_8);
        s21_dec_zero(value);
        s21_left_shift_bit(&mul_2, 1);
        s21_left_shift_bit(&mul_8, 3);
        s21_add(mul_2, mul_8, value);
    }
    if (sign) {
        s21_set_sign(value);
    }
}
