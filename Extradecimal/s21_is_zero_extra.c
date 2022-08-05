//
//  s21_is_zero_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/15/22.
//

#include "s21_decimal_extra.h"

int s21_is_zero_extra(s21_decimal_extra decimal) {
    int ex_code = 1;

    for (int i = 0; i < EXTRASIZE; i++) {
        if (decimal.bits[i] != 0) {
            ex_code = 0;
            break;
        }
    }

    return ex_code;
}
