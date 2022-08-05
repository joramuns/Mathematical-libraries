//
//  s21_dec_zero_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#include "s21_decimal_extra.h"

void s21_dec_zero_extra(s21_decimal_extra *decimal) {
    for (int i = 0; i < EXTRASIZE; i++) {
        decimal->bits[i] = 0;
    }
}
