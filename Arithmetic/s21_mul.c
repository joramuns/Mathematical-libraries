//
//  s21_mul.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal zero, temp;
    s21_dec_zero(&zero);
    int ex_code = 0;
    while (s21_is_not_equal(value_2, zero) && !ex_code) {
        if (s21_get_bit_long(value_2, 0)) {
            s21_dec_copy(*result, &temp);
            s21_dec_zero(result);
            ex_code = s21_add(temp, value_1, result);
        }
        s21_left_shift_bit(&value_1, 1);
        s21_right_shift_bit(&value_2, 1);
    }

    return ex_code;
}
