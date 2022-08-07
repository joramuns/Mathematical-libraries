//
//  s21_add.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_sum_dec(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    int len = (s21_last_non_zero(value_1) >= s21_last_non_zero(value_2)) ? \
    s21_last_non_zero(value_1) : s21_last_non_zero(value_2);

    for (int i = 0; (i <= len) && !ex_code; i++) {
        ex_code = s21_sum_bit(i, result, s21_get_bit_long(value_1, i));
        if (!ex_code) ex_code = s21_sum_bit(i, result, s21_get_bit_long(value_2, i));
    }

    return ex_code;
}

int s21_sum_dec_extra(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    s21_decimal_extra value_1_extra = {0}, value_2_extra = {0}, result_extra = {0};

    s21_dec_to_exdec(value_1, &value_1_extra);
    s21_dec_to_exdec(value_2, &value_2_extra);
    int len = (s21_last_non_zero_extra(value_1_extra) >= s21_last_non_zero_extra(value_2_extra)) ? \
    s21_last_non_zero_extra(value_1_extra) : s21_last_non_zero_extra(value_2_extra);

    for (int i = 0; (i <= len) && !ex_code; i++) {
        ex_code = s21_sum_bit_extra(i, &result_extra, s21_get_bit_long_extra(value_1_extra, i));
        if (!ex_code) ex_code = s21_sum_bit_extra(i, &result_extra, s21_get_bit_long_extra(value_2_extra, i));
    }
//    if (s21_get_sub_flag(*result)) s21_right_shift_bit_extra(&result_extra, 1);
    s21_exdec_to_dec(result_extra, result);

    return ex_code;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0, dif_scale = 0;
    int sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);
    int scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
    if (scale_1 != scale_2) {
        dif_scale = (scale_1 > scale_2) ? scale_1 : scale_2;
        s21_scale_equalize(&value_1, &value_2);
    }

    s21_zero_bit(&value_1, 127);
    s21_zero_bit(&value_2, 127);
    if ((!sign_1 && !sign_2) || (sign_1 && sign_2)) {
        ex_code = s21_sum_dec(value_1, value_2, result);
        if (ex_code && s21_get_sign(*result)) ex_code = 0;
        if (sign_1 && sign_2) s21_set_sign(result);
    } else if (sign_1) {
        ex_code = s21_sub(value_2, value_1, result);
    } else if (sign_2) {
        ex_code = s21_sub(value_1, value_2, result);
    }
    s21_set_scale(result, dif_scale);
    if (ex_code) {
        if (s21_get_sign(*result)) ex_code = 2;
        s21_dec_zero(result);
    }

    return ex_code;
}

// 5.(3) + 5.(3) ??? (28 scales)
