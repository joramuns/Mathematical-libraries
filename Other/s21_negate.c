//
//  s21_negate.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
    *result = value;
    int sign = s21_get_sign(value);
    if (sign) {
        s21_zero_bit(result, 127);
    } else {
        s21_set_sign(result);
    }
    return 0;
}
