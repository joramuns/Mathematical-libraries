//
//  s21_get_bit_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

int s21_get_bit_long_extra(s21_decimal_extra decimal, int bit_index) {
    int i = bit_index / 32;
    bit_index %= 32;
    return (decimal.bits[i] & (1 << bit_index)) ? 1 : 0;
}
