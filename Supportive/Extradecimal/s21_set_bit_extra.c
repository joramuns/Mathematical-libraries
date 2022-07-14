//
//  s21_set_bit_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

void s21_set_bit_extra(s21_decimal *decimal, int bit_index) {
    int i = bit_index / 32;
    bit_index %= 32;
    decimal->bits[i] |= (1 << bit_index);
}
