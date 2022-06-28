//
//  s21_set_bit.c
//  Decimal
//

#include "../s21_decimal.h"

void s21_set_bit(s21_decimal *decimal, int bit_index) {
    int i = bit_index / 32;
    bit_index %= 32;
    decimal->bits[i] |= (1 << bit_index);
}