//
//  s21_add.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    int len = (s21_last_non_zero(value_1) >= s21_last_non_zero(value_2)) ? s21_last_non_zero(value_1) : s21_last_non_zero(value_2);

    for (int i = 0; (i <= len) && !ex_code; i++) {
        ex_code = s21_sum_bit(i, result, s21_get_bit_long(value_1, i));
        ex_code = s21_sum_bit(i, result, s21_get_bit_long(value_2, i));
    }

    return ex_code;
}


