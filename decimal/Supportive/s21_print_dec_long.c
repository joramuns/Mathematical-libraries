//
//  s21_print_dec_long.c
//  Decimal
//

#include "../s21_decimal.h"

void s21_print_dec_long(s21_decimal number) {
    for (int i = 96; i > 0; i--) {
        putchar(s21_get_bit_long(number, i - 1) + '0');
    }
    putchar('\n');
}
