//
//  s21_zero_bit.c
//  Decimal
//
#include "../s21_decimal.h"

void s21_zero_bit(s21_decimal *decimal, int bit_index) {
    int i = bit_index / 32;
    bit_index %= 32;
    decimal->bits[i] &= ~(1U << bit_index);
}
