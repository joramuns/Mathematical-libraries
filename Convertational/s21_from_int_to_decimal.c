//
//  s21_from_int_to_decimal.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int error = 0;
    if (src >= 0) {
        dst->bits[0] = src;
    } else {
        src = -src;
        dst->bits[0] = src;
        s21_set_sign(dst);
    }
    return error;
}
