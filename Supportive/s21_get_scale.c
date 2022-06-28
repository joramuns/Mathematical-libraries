//
//  s21_get_scale.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_get_scale(s21_decimal decimal) {
    int scale = 0;
    for (int i = 23; i > 15; i--) {
        scale <<= 1;
        scale |= s21_get_bit(decimal.bits[3], i);
    }
    return scale;
}
