//
//  s21_print_decimal.c
//  Decimal
//

#include "../s21_decimal.h"

void s21_print_decimal(s21_decimal number) {
    for (int i = 0; i < 4; i++) {
        char *binary = s21_get_block(number.bits[i]);
        printf("bit[%d] %s %u\n", i, binary, number.bits[i]);
        free(binary);
    }
}
