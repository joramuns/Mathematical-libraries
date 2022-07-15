//
//  s21_exdec_to_dec.c
//  Decimal
//
//  Created by Joramun Sasin on 7/15/22.
//

#include "s21_decimal_extra.h"

int s21_exdec_to_dec(s21_decimal_extra src, s21_decimal *dest) {
    int ex_code = 0;

    for (int i = 0; i < DECIMSIZE; i++) {
        dest->bits[i] = src.bits[i];
    }

    return ex_code;
}