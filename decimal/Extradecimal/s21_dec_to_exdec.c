//
//  s21_exdec_to_dec.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

int s21_dec_to_exdec(s21_decimal src, s21_decimal_extra *dest) {
    int ex_code = 0;

    for (int i = 0; i < EXTRASIZE; i++) {
        if (i < 3) {
            dest->bits[i] = src.bits[i];
        } else {
            dest->bits[i] = 0;
        }
    }

    return ex_code;
}
