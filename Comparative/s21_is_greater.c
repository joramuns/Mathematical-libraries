//
//  s21_is_greater.c
//  Decimal
//  без учета scale

#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
    int result = 2;
    if (s21_get_sign(value_1) != s21_get_sign(value_2)) {
        result = s21_get_sign(value_1) ? 0 : 1;
    }
    for (int i = 95; i > -1 && result == 2; i--) {
        if (s21_get_bit_long(value_1, i) != s21_get_bit_long(value_2, i)) {
            result = s21_get_sign(value_1) == 0 ? \
            s21_get_bit_long(value_1, i) : !s21_get_bit_long(value_1, i);
        }
    }
    if (result == 2) {
        result = 0;
    }
    return result;
}
