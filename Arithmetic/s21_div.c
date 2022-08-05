//
//  s21_div.c
//  Decimal
//


#include <stdio.h>
#include "../s21_decimal.h"

s21_decimal_extra s21_dec_and(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    s21_decimal_extra result;
    s21_dec_zero_extra(&result);

    for (int i = 0; i < EXTRASIZE; i++) {
        result.bits[i] = value_1.bits[i] & value_2.bits[i];
    }

    return result;
}

s21_decimal_extra s21_dec_or(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    s21_decimal_extra result;
    s21_dec_zero_extra(&result);

    for (int i = 0; i < EXTRASIZE; i++) {
        result.bits[i] = value_1.bits[i] | value_2.bits[i];
    }

    return result;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0, scale = 28;
    s21_decimal_extra remainder, one, res_dec, res_extra, value_1_extra, value_2_extra;
    s21_dec_zero_extra(&res_extra);
    s21_dec_zero_extra(&remainder);
    s21_dec_to_exdec(value_1, &value_1_extra);
    s21_mul_ten_extra(&value_1_extra, scale);
    scale += s21_get_scale(value_1);
    scale += s21_get_scale(value_2);
    s21_dec_to_exdec(value_2, &value_2_extra);

    for (int i = EXTRALASTBIT; i >= 0; i--) {
        s21_left_shift_bit_extra(&res_extra, 1);
        s21_left_shift_bit_extra(&remainder, 1);
        s21_dec_zero_extra(&one);
        one.bits[0] = 1;
        s21_dec_zero_extra(&res_dec);

        s21_left_shift_bit_extra(&one, i);
        res_dec = s21_dec_and(value_1_extra, one);
        s21_right_shift_bit_extra(&res_dec, i);

        remainder = s21_dec_or(remainder, res_dec);

        if (!s21_is_less_extra(remainder, value_2_extra)) {
            s21_dec_copy_extra(remainder, &res_dec);
            s21_dec_zero_extra(&remainder);
            ex_code = s21_sub_extra(res_dec, value_2_extra, &remainder);
            s21_dec_zero_extra(&one);
            one.bits[0] = 1;
            res_extra = s21_dec_or(res_extra, one);
        }
    }
    if (scale > 28) {
        s21_div_ten_extra(&res_extra, scale - 28);
    }
    s21_exdec_to_dec(res_extra, result);
    s21_set_scale(result, 28);
    while (!s21_truncate_zero(result)) {}

    return ex_code;
}
