//
//  get_sign.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_get_sign(s21_decimal decimal) {
    return s21_get_bit_long(decimal, 127);
}
