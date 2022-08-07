//
//  s21_sub_flag.c
//  Decimal
//
//  Created by Joramun Sasin on 8/7/22.
//

#include "s21_decimal.h"

void s21_set_sub_flag(s21_decimal *value) {
    value->bits[3] |= 1U << 1;
}

void s21_zero_sub_flag(s21_decimal *value) {
    value->bits[3] &= ~(1 << 1);
}

int s21_get_sub_flag(s21_decimal value) {
    return s21_get_bit(value.bits[3], 1);
}
