//
//  s21_sub_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/15/22.
//
//  Only value_1 > value_2 case and unsigned decimal!

#include "s21_decimal_extra.h"

void s21_invert_bit_long_extra(s21_decimal_extra *value) {
    for (int i = 0; i < EXTRASIZE; i++) {
        value->bits[i] = ~value->bits[i];
    }
}

int s21_sub_extra(s21_decimal_extra value_1, s21_decimal_extra value_2, s21_decimal_extra *result) {

    s21_invert_bit_long_extra(&value_2);
    s21_set_bit_extra(result, 0);
    s21_add_extra(value_1, value_2, result);

    return 0;
}
