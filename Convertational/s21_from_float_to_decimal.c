//
//  s21_from_float_to_decimal.c
//  Decimal
//
#include <string.h>
#include "../s21_decimal.h"

int s21_get_float_exp(float src) {
    int exp = 0;
    int input = 0;
    memcpy(&input, &src, 4);
    exp = ((input >> 23) & 0xff) - 127;
    return exp;
}

int s21_get_float_mantissa(float src) {
    int mantissa = 0;
    int input = 0;
    memcpy(&input, &src, 4);
    mantissa = (input & 0x7fffff);
    return mantissa;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int ex_code = 0;
    int exp = s21_get_float_exp(src);
    int scale = 0;
    if (exp <= -96) {
        ex_code = 1;
    } else if (exp > -96 && exp <= 0) {
        float new_src;
        new_src = src * 10000000;
        scale = 7;  // добавить функцию установить масшаб
        s21_from_int_to_decimal(new_src, dst);
    } else if (exp > 0 && exp <= 22) {
        if (src >= 1000000) {
            s21_from_int_to_decimal(src, dst);
        } else if(src < 1000000 && src >= 100000) {
            s21_from_int_to_decimal(src*10, dst);
            scale = 1;
        } else if(src < 100000 && src >= 10000) {
            s21_from_int_to_decimal(src*100, dst);
            scale = 2;
        } else if (src < 10000 && src >= 1000) {
            s21_from_int_to_decimal(src*1000, dst);
            scale = 3;
        } else if (src < 10000) {
            s21_from_int_to_decimal(src*10000, dst);
            scale = 4;
        }
    } else if (exp < 96 && exp > 22) {
        int mantissa = s21_get_float_mantissa(src);
        dst->bits[0] = mantissa;
        s21_set_bit(dst, 23);
        s21_shift_bit(dst, exp - 23);
    } else if (exp >= 96) {
        ex_code = 1;
    }
    printf("%d\n\n", scale);
    return ex_code;
}
