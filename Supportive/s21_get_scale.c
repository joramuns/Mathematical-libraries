//
//  s21_get_scale.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_get_scale(s21_decimal decimal) {
    int scale = decimal.bits[3];

    scale <<= 1;
    scale >>= 17;

    return scale;
}
