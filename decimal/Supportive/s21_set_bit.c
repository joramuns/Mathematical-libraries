//
//  s21_set_bit.c
//  Decimal
//
//  Array starts from index 0 here.
//  Decimal indexes: [0, 1, 2, 3, ..., 95]

#include "../s21_decimal.h"

void s21_set_bit(s21_decimal *decimal, int bit_index) {
    int i = bit_index / 32;
    bit_index %= 32;
    decimal->bits[i] |= (1U << bit_index);
}
