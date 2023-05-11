//
//  s21_is_not_equal.c
//  Decimal
//  без учета scale

#include "../s21_decimal.h"

int s21_is_not_equal_noscale(s21_decimal value_1, s21_decimal value_2) {
    return !s21_is_equal_noscale(value_1, value_2);
}
