//
//  s21_get_block.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

char *s21_get_block(int block) {
    char *str_block = malloc(BITSIZE + 1 * sizeof(char));

    for (int i = 0; i < BITSIZE; i++) {
        str_block[BITSIZE - 1 - i] = s21_get_bit(block, i) + '0';
    }
    str_block[32] = '\0';

    return str_block;
}
