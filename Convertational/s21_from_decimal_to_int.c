//
//  s21_from_decimal_to_int.c
//  Decimal
//  без учета scale

#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int error = 0;
    if (src.bits[2] != 0 || src.bits[1] != 0 || s21_get_bit(src.bits[0], 31) == 1) {
        error = 1;
    }
    if (error == 0) {
        *dst = (int)src.bits[0];
        if (s21_get_scale(src)) {
            *dst = ~*dst;
            *dst |= 1U << 31;
        }
    }
    return error;
}
