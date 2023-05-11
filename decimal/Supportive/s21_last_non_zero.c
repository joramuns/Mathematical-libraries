//
//  s21_last_non_zero.c
//  Decimal
//
// Function is searching for the first non zero bit in decimal

#include "../s21_decimal.h"

int s21_last_non_zero(s21_decimal decimal) {
    int bit_index = 95;

    for (; bit_index >= 0; bit_index--) {
        if (s21_get_bit_long(decimal, bit_index)) break;
    }
    return bit_index;
}
