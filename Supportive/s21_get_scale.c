//
//  s21_get_scale.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_get_scale(s21_decimal decimal) {
    return (decimal.bits[3] & (1 << 31)) ? 1 : 0;
}
