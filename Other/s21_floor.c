//
//  s21_floor.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
    int sign = s21_get_sign(value);
    if (sign) {
        s21_truncate(value, result);
        if (!s21_is_equal(value, *result)) {
            s21_decimal one = {1, 0, 0, 0};
            s21_sub(value, one, result);
            s21_truncate(*result, result);
        }
    } else {
        s21_truncate(value, result);
    }
    return 0;
}
