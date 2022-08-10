//
//  s21_scale_equalize_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 8/10/22.
//

#include "s21_decimal_extra.h"

int s21_scale_eq_mul_extra(s21_decimal_extra *value, int scale_present, int scale_target) {
    int ex_code = 0;
    s21_decimal_extra temp_dec = *value;

    while (scale_present < scale_target && !ex_code) {
        ex_code = s21_mul_ten_extra(&temp_dec, 1);
        if (!ex_code) {
            s21_dec_copy_extra(temp_dec, value);
            scale_present++;
        } else {
            break;
        }
    }
    ex_code = scale_present;

    return ex_code;
}

int s21_scale_eq_div_extra(s21_decimal_extra *value, int scale_present, int scale_target) {
    int ex_code = 0;
    s21_decimal_extra temp_dec = *value;

    while (scale_present > scale_target) {
        if ((scale_present - scale_target) > 1) {
            ex_code = s21_div_ten_extra(&temp_dec, 1);
            s21_dec_copy_extra(temp_dec, value);
        } else {
            s21_bank_rounding_extra(value);
        }
        scale_present--;
    }

    return ex_code;
}

int s21_scale_equalize_extra(s21_decimal_extra *value_1, s21_decimal_extra *value_2, \
                             int scale_1, int scale_2) {
    int ex_code = 0;

    if (scale_1 < scale_2) {
        scale_1 = s21_scale_eq_mul_extra(value_1, scale_1, scale_2);
        if (scale_1 != scale_2) {
            ex_code = s21_scale_eq_div_extra(value_2, scale_2, scale_1);
        }
    } else if (scale_1 > scale_2) {
        scale_2 = s21_scale_eq_mul_extra(value_2, scale_2, scale_1);
        if (scale_2 != scale_1) {
            ex_code = s21_scale_eq_div_extra(value_1, scale_1, scale_2);
        }
    }
    if (scale_1 == scale_2) {
        ex_code = scale_1;
    } else {
        ex_code = 99;
    }

    return ex_code;
}
