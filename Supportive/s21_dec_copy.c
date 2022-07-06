//
//  s21_dec_copy.c
//  Decimal
//
//  Created by Joramun Sasin on 7/6/22.
//

#include "s21_decimal.h"

void s21_dec_copy(s21_decimal src, s21_decimal *dest) {
    for (int i = 0; i < 4; i++) {
        dest->bits[i] = src.bits[i];
    }
}
