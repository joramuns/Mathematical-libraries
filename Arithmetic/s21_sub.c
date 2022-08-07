//
//  s21_sub.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

void s21_invert_bit_long(s21_decimal *value) {
    value->LOWBIT = ~value->LOWBIT;
    value->MEDBIT = ~value->MEDBIT;
    value->HIGHBIT = ~value->HIGHBIT;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0, sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);

    if (sign_1 && sign_2) {
        s21_zero_bit(&value_1, 127);
        s21_zero_bit(&value_2, 127);
        ex_code = s21_sub(value_2, value_1, result);
    } else if (!sign_1 && !sign_2) {
        if (s21_is_equal_noscale(value_1, value_2)) {
            s21_dec_zero(result);
        } else {
            s21_set_bit(result, 0);
            s21_set_sign(result);
            if (s21_is_greater_noscale(value_1, value_2)) {
                s21_invert_bit_long(&value_2);
                s21_set_sub_flag(result);
                ex_code = s21_add(value_1, value_2, result);
                s21_zero_bit(result, 127);
                s21_zero_sub_flag(result);
            } else {
                s21_invert_bit_long(&value_1);
                s21_set_sub_flag(result);
                ex_code = s21_add(value_2, value_1, result);
                s21_zero_sub_flag(result);
            }
        }
    } else if (sign_1) {
        s21_zero_bit(&value_1, 127);
        ex_code = s21_add(value_1, value_2, result);
        if (!ex_code) {
            s21_set_sign(result);
        } else {
            ex_code = 2;
        }
    } else if (sign_2) {
        s21_zero_bit(&value_2, 127);
        ex_code = s21_add(value_1, value_2, result);
    }

    return ex_code;
}
