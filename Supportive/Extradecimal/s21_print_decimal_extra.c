//
//  s21_print_decimal_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

void s21_print_decimal_extra(s21_decimal_extra number) {
    for (int i = 0; i < 6; i++) {
        char *binary = s21_get_block_extra(number.bits[i]);
        printf("bit[%d] %s %u\n", i, binary, number.bits[i]);
        free(binary);
    }
}
