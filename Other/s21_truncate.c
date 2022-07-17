//
//  s21_truncate.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
    *result = value;
    int scale = s21_get_scale(*result);
    while (scale > 0) {
        s21_div_ten(result);
        scale--;
    }
    return 0;
}
