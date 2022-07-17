//
//  s21_from_float_to_decimal.c
//  Decimal
//

#include <string.h>
#include <math.h>
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
        s21_dec_zero(dst);
    } else if (exp > -96 && exp <= 0) {
        float new_src;
        new_src = src * 10000000;
        scale = 7;
        s21_from_int_to_decimal(new_src, dst);
        s21_set_scale(dst, scale);
    } else if (exp > 0 && exp <= 22) {
        scale = 6;
        int sign = 0;
        if (src < 0) {
            sign = 1;
            src = -src;
        }
        float new_src = src;
        while (new_src/10 > 1) {
            new_src = new_src/10;
            scale--;
        }
        
        new_src = src * pow(10, scale);
        s21_from_int_to_decimal(new_src, dst);
        s21_set_scale(dst, scale);
        if (sign) s21_set_sign(dst);
        
    } else if (exp < 96 && exp > 22) {
        int mantissa = s21_get_float_mantissa(src);
        dst->bits[0] = mantissa;
        s21_set_bit(dst, 23);
        s21_left_shift_bit(dst, exp - 23);
        if (src < 0) s21_set_sign(dst);
    } else if (exp >= 96) {
        ex_code = 1;
    }
    return ex_code;
}
