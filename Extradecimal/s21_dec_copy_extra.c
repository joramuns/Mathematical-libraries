//
//  s21_dec_copy_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

void s21_dec_copy_extra(s21_decimal_extra src, s21_decimal_extra *dest) {
    for (int i = 0; i < EXTRASIZE; i++) {
        dest->bits[i] = src.bits[i];
    }
}
