//
//  s21_get_bit_long.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_get_bit_long(s21_decimal decimal, int bit_index) {
    int i = bit_index / 32;
    bit_index %= 32;
    return (decimal.bits[i] & (1U << bit_index)) ? 1 : 0;
}


