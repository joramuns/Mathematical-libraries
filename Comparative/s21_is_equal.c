//
//  s21_is_equal.c
//  Decimal
//
// ±0 разные числа, и функция вернет 0, т.е. нет - поменять???

#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    int ex_code = s21_scale_equalize(&value_1, &value_2) + 1;
    
    for (int i = 0; i < 128 && ex_code == 1; i++) {
        if (s21_get_bit_long(value_1, i) != s21_get_bit_long(value_2, i)) {
            ex_code = 0;
        }
    }
    return ex_code;
} 
