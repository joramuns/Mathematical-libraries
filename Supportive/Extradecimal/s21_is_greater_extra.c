//
//  s21_is_not_equal_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//
//  Signs don't matter at all, working only with unsigned extra decimal

#include "s21_decimal_extra.h"

int s21_is_greater_extra(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    int result = 0;

    for (int i = EXTRALASTBIT; i >= 0; i--) {
        if (s21_get_bit_long_extra(value_1, i) != s21_get_bit_long_extra(value_2, i)) {
            result = s21_get_bit_long_extra(value_1, i) ? 1 : 0;
            break;
        }
    }

    return result;
}
