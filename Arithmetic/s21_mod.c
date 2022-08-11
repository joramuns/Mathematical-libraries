//
//  s21_mod.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    s21_decimal temp = INITDEC, temp2 = INITDEC;
    int sign = s21_get_sign(value_2);
    if (sign) sign = s21_get_sign(value_1);
    s21_zero_bit(&value_1, 127);
    s21_zero_bit(&value_2, 127);

    ex_code = s21_div(value_1, value_2, &temp);
    if (!ex_code) {
        if (s21_is_equal(value_1, temp2)) {
            s21_dec_copy(temp, result);
        } else {
            s21_truncate(temp, &temp2);
            s21_dec_zero(&temp);
            s21_mul(value_2, temp2, &temp);
            s21_sub(value_1, temp, result);
            if (sign) s21_set_sign(result);
        }
    }

    return ex_code;
}
