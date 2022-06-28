//
//  s21_add.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    int len = (s21_last_non_zero(value_1) >= s21_last_non_zero(value_2)) ? s21_last_non_zero(value_1) : s21_last_non_zero(value_2);

    for (int i = 0; i < len; i++) {
        
    }

    return ex_code;
}
