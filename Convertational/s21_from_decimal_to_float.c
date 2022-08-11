//
//  s21_from_decimal_to_float.c
//  Decimal
//

#include <math.h>
#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int ex_code = 0;
    *dst = 0;
    long double a = 0;
    for (int i = 95; i > -1; i--) {
        a += s21_get_bit_long(src, i) * pow(2, i);
        }
    for (int scale = s21_get_scale(src); scale > 0; scale--) {
        a /= 10;
    }
    if (s21_get_sign(src)) {
        a *= -1;
    }
    *dst = (float)a;
    return ex_code;
}
