//
//  s21_get_bit_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

int s21_get_bit_extra(int block, int num_bit) {
    return (block & (1 << num_bit)) ? 1 : 0;
}
