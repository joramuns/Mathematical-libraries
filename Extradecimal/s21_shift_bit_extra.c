//
//  s21_shift_bit_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

void s21_left_shift_bit_extra(s21_decimal_extra *decimal, int step) {
    int temp[EXTRASIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (; step > 0; step--) {
        for (int i = 0; i < EXTRASIZE; i++) {
            temp[i] = s21_get_bit_extra(decimal->bits[i], 31);
            decimal->bits[i] <<= 1;
            if (i > 0 && temp[i - 1]) {
                s21_set_bit_extra(decimal, i * 32);
            }
        }
    }
}

void s21_right_shift_bit_extra(s21_decimal_extra *decimal, int step) {
    int temp[EXTRASIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (; step > 0; step--) {
        for (int i = (EXTRASIZE - 1); i >= 0; i--) {
            temp[i] = s21_get_bit_extra(decimal->bits[i], 0);
            decimal->bits[i] >>= 1;
            if (i < (EXTRASIZE - 1) && temp[i + 1]) {
                s21_set_bit_extra(decimal, i * 32 + 31);
            }
        }
    }
}
