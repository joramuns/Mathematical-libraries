//
//  s21_is_less.c
//  Decimal
//  без учета scale

#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    int result;
    result = !s21_is_greater(value_1, value_2);
    if (s21_is_equal (value_1, value_2)) result = 0;
    return result;
}
