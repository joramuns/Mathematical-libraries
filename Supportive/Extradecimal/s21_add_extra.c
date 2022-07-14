//
//  s21_add_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

int s21_sum_bit_extra(int i, s21_decimal_extra *result, int add_bit) {
    int ex_code = 0;
    int res_bit = s21_get_bit_long_extra(*result, i);

    if (add_bit ^ res_bit) {
        s21_set_bit_extra(result, i);
    } else if (add_bit & res_bit) {
        s21_zero_bit_extra(result, i);
        if ((i + 1) < 192) {
            s21_set_bit_extra(result, i + 1);
        } else {
            ex_code = 1;
        }
    }
    return ex_code;
}

int s21_add_extra(s21_decimal_extra value_1, s21_decimal_extra value_2, s21_decimal_extra *result) {
    int ex_code = 0;
    int len = (s21_last_non_zero_extra(value_1) >= s21_last_non_zero_extra(value_2)) ? \
    s21_last_non_zero_extra(value_1) : s21_last_non_zero_extra(value_2);

    for (int i = 0; (i <= len) && !ex_code; i++) {
        ex_code = s21_sum_bit_extra(i, result, s21_get_bit_long_extra(value_1, i));
        if (!ex_code) ex_code = s21_sum_bit_extra(i, result, s21_get_bit_long_extra(value_2, i));
    }
    return ex_code;
}
