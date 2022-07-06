//
//  s21_from_decimal_to_float.c
//  Decimal
//

#include <math.h>
#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int error = 0;
    *dst = 0;
    for (int i = 95; i > -1; i--) {
        *dst += s21_get_bit_long(src, i) * pow(2, i);
        }
    if (s21_get_sign(src)) {
        *dst *= -1;
    }
    for (int i = s21_get_scale(src); i > 0; i--) {
        *dst /= 10;
    }
    return error;
}
