//
//  s21_set_scale.c
//  Decimal
//

#include "s21_decimal.h"

int s21_set_scale(s21_decimal *decimal, int scale) {
    int ex_code = 0;
    int sign = s21_get_sign(*decimal);
    decimal->bits[3] = 0;

    if (scale > 0 && scale < 29) {
        scale <<= 16;
        decimal->bits[3] |= scale;
        if (sign) s21_set_sign(decimal);
    } else {
        ex_code = 1;
    }

    return ex_code;
}
