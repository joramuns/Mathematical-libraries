//
//  s21_round.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
    
    int sign = s21_get_sign(value);
    if (sign) s21_zero_bit(&value, 127);
    
    s21_decimal value_truncate;
    s21_truncate(value, &value_truncate);
    s21_decimal diff;
    s21_sub(value, value_truncate, &diff);
    
    s21_decimal five = {5, 0, 0, 65536};
    s21_decimal one = {1, 0, 0, 0};
    int compare;
    
    compare = s21_is_greater_or_equal(diff, five);
    if(compare) {
        s21_add(value_truncate, one, result);
    } else {
        *result = value_truncate;
    }

    if (sign) s21_set_sign(result);
    
    return 0;
}
