//
//  s21_zero_bit_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

void s21_zero_bit_extra(s21_decimal_extra *decimal, int bit_index) {
    int i = bit_index / 32;
    bit_index %= 32;
    decimal->bits[i] &= ~(1 << bit_index);
}
