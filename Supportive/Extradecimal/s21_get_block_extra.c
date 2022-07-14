//
//  s21_get_block_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

char *s21_get_block_extra(int block) {
    char *str_block = malloc(32 + 1 * sizeof(char));

    for (int i = 0; i < 32; i++) {
        str_block[32 - 1 - i] = s21_get_bit_extra(block, i) + '0';
    }
    str_block[32] = '\0';

    return str_block;
}
