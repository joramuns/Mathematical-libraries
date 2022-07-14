//
//  s21_set_scale.c
//  Decimal
//

#include "s21_decimal.h"

int s21_set_scale(s21_decimal *decimal, int scale) {
    int ex_code = 0;

    if (scale < 29) {
        scale <<= 16;
        decimal->bits[3] |= scale;
    } else {
        ex_code = 1;
    }

    return ex_code;
}
