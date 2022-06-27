//
//  s21_get_bit.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_get_bit(int block, int num_bit) {
    return (block & (1 << num_bit)) ? 1 : 0;
}
