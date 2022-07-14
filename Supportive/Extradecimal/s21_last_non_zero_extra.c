//
//  s21_last_non_zero_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

int s21_last_non_zero_extra(s21_decimal_extra decimal) {
    int bit_index = 191;

    for (; bit_index >= 0; bit_index--) {
        if (s21_get_bit_long_extra(decimal, bit_index)) break;
    }
    return bit_index;
}
