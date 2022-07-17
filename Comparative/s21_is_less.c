//
//  s21_is_less.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    int ex_code;
    ex_code = !s21_is_greater(value_1, value_2);
    if (s21_is_equal (value_1, value_2)) ex_code = 0;
    return ex_code;
}
