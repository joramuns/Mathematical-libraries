//
//  s21_set_bit.c
//  Decimal
//

#include "../s21_decimal.h"
// 0 - 96
void s21_set_bit(int *bit, int index) {
    *bit |= 1 << index;
}
