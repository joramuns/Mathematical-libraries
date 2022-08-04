//
//  s21_is_equal_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 8/4/22.
//

#include "s21_decimal_extra.h"

int s21_is_equal_extra(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    int result = 1;

    for (int i = 0; i < EXTRASIZE && result; i++) {
        if (value_1.bits[i] != value_2.bits[i]) result = 0;
    }

    return result;
}
