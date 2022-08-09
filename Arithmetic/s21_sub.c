//
//  s21_sub.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"

int s21_sub_bit(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0, dif_scale = 0;
    s21_decimal_extra zero_extra = INITDECEXTRA;
    s21_decimal_extra value_1_extra = INITDECEXTRA, value_2_extra = INITDECEXTRA;
    s21_dec_to_exdec(value_1, &value_1_extra);
    s21_dec_to_exdec(value_2, &value_2_extra);

    while (!s21_is_equal_extra(value_2_extra, zero_extra)) {
        s21_decimal_extra inverted_x = s21_invert_dec_extra(value_1_extra);
        s21_decimal_extra borrow = s21_dec_and(inverted_x, value_2_extra);
        value_1_extra = s21_dec_xor(value_1_extra, value_2_extra);
        s21_left_shift_bit_extra(&borrow, 1);
        value_2_extra = borrow;
    }

    dif_scale -= s21_exdec_to_dec(value_1_extra, result);
    if (dif_scale < 0) {
        ex_code = 1;
    } else {
        s21_set_scale(result, dif_scale);
    }

    return ex_code;
}

void s21_invert_bit_long(s21_decimal *value) {
    value->LOWBIT = ~value->LOWBIT;
    value->MEDBIT = ~value->MEDBIT;
    value->HIGHBIT = ~value->HIGHBIT;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0, dif_scale = 0, sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);
    int scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
    if (scale_1 != scale_2) {
        s21_scale_equalize(&value_1, &value_2);
        scale_1 = s21_get_scale(value_1);
        scale_2 = s21_get_scale(value_2);
        if (scale_1 == scale_2) {
            dif_scale = scale_1;
        } else {
            ex_code = 99;  // THIS IS SPARTA
        }
    }

    if (sign_1 && sign_2) {
        s21_zero_bit(&value_1, 127);
        s21_zero_bit(&value_2, 127);
        ex_code = s21_sub(value_2, value_1, result);
    } else if (!sign_1 && !sign_2) {
        if (s21_is_equal_noscale(value_1, value_2)) {
            s21_dec_zero(result);
        } else {
//            s21_set_bit(result, 0);
//            s21_set_sign(result);
            if (s21_is_greater_noscale(value_1, value_2)) {
                ex_code = s21_sub_bit(value_1, value_2, result);
            } else {
                ex_code = s21_sub_bit(value_2, value_1, result);
                s21_set_sign(result);
            }
        }
    } else if (sign_1) {
        s21_zero_bit(&value_1, 127);
        ex_code = s21_add(value_1, value_2, result);
        if (!ex_code) {
            s21_set_sign(result);
        } else {
            ex_code = 2;
        }
    } else if (sign_2) {
        s21_zero_bit(&value_2, 127);
        ex_code = s21_add(value_1, value_2, result);
    }
    s21_set_scale(result, dif_scale);

    return ex_code;
}
