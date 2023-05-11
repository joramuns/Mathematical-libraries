//
//  s21_is_equal.c
//  Decimal
//  без учета scale
// ±0

#include "../s21_decimal.h"

int s21_is_equal_noscale(s21_decimal value_1, s21_decimal value_2) {
    int result = 1;
    for (int i = 0; i < 96 && result == 1; i++) {
        if (s21_get_bit_long(value_1, i) != s21_get_bit_long(value_2, i)) {
            result = 0;
        }
    }
    return result;
}
