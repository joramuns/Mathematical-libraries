//
//  s21_floor.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
    int sign = s21_get_sign(value);

    s21_truncate(value, result);
    if (sign) {
        if (!s21_is_equal(value, *result)) {
            s21_decimal one = INITDECONE;
            s21_sub(*result, one, result);
        }
    }
    return 0;
}
