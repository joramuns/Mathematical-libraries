//
//  s21_get_bit.c
//  Decimal
//
//  Array starts from index 0 here.
//  Decimal indexes: [0, 1, 2, ..., 30, 31]

#include "../s21_decimal.h"

int s21_get_bit(int block, int num_bit) {
    return (block & (1U << num_bit)) ? 1 : 0;
}
