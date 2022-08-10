//
//  s21_scale_equalize.c
//  Decimal
//
//  Created by Alyssa Ivana on 7/16/22.
//

#include "../s21_decimal.h"

int s21_scale_eq_mul(s21_decimal *value, int scale_present, int scale_target) {
    int ex_code = 0;
    s21_decimal temp_dec = *value;

    while (scale_present < scale_target && !ex_code) {
        ex_code = s21_mul_ten(&temp_dec);
        if (!ex_code) {
            s21_dec_copy(temp_dec, value);
            scale_present++;
        } else {
            break;
        }
    }
    ex_code = scale_present;

    return ex_code;
}

int s21_scale_eq_div(s21_decimal *value, int scale_present, int scale_target) {
    int ex_code = 0;
    s21_decimal temp_dec = *value;

    while (scale_present > scale_target) {
        if ((scale_present - scale_target) > 1) {
            ex_code = s21_div_ten(&temp_dec);
            s21_dec_copy(temp_dec, value);
        } else {
            s21_bank_rounding(value);
        }
        scale_present--;
    }

    return ex_code;
}

int s21_scale_equalize(s21_decimal *value_1, s21_decimal *value_2) {
    int ex_code = 0;
    int scale_1 = s21_get_scale(*value_1), scale_2 = s21_get_scale(*value_2);

    if (scale_1 < scale_2) {
        scale_1 = s21_scale_eq_mul(value_1, scale_1, scale_2);
        if (scale_1 != scale_2) {
            ex_code = s21_scale_eq_div(value_2, scale_2, scale_1);
        }
    } else if (scale_1 > scale_2) {
        scale_2 = s21_scale_eq_mul(value_2, scale_2, scale_1);
        if (scale_2 != scale_1) {
            ex_code = s21_scale_eq_div(value_1, scale_1, scale_2);
        }
    }

    return ex_code;
}
