//
//  s21_add.c
//  Decimal
//

#include "../s21_decimal.h"

s21_decimal_extra s21_sum_dec_extra(s21_decimal_extra value_1_extra, s21_decimal_extra value_2_extra) {
    s21_decimal_extra zero_extra = INITDECEXTRA;

    while (!s21_is_equal_extra(value_2_extra, zero_extra)) {
        s21_decimal_extra sum = s21_dec_xor(value_1_extra, value_2_extra);
        s21_decimal_extra carry = s21_dec_and(value_1_extra, value_2_extra);
        s21_left_shift_bit_extra(&carry, 1);
        value_1_extra = sum;
        value_2_extra = carry;
    }

    return value_1_extra;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    // Convert to extradecimal
    s21_decimal_extra value_1_extra = INITDECEXTRA, value_2_extra = INITDECEXTRA;
    s21_dec_to_exdec(value_1, &value_1_extra);
    s21_dec_to_exdec(value_2, &value_2_extra);
    //
    int ex_code = 0, dif_scale = 0;
    int sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);
    int scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
    if (scale_1 != scale_2) {
        dif_scale = s21_scale_equalize_extra(&value_1_extra, &value_2_extra, scale_1, scale_2);
    } else {
        dif_scale = scale_1;
    }

    s21_zero_bit(&value_1, 127);
    s21_zero_bit(&value_2, 127);
    if ((!sign_1 && !sign_2) || (sign_1 && sign_2)) {
        s21_decimal_extra result_extra = s21_sum_dec_extra(value_1_extra, value_2_extra);
        if (ex_code && s21_get_sign(*result)) ex_code = 0;
        if (sign_1 && sign_2) s21_set_sign(result);
        dif_scale -= s21_exdec_to_dec(result_extra, result);
        if (dif_scale < 0) {
            ex_code = 1;
        } else {
            s21_set_scale(result, dif_scale);
        }
    } else if (sign_1) {
        ex_code = s21_sub(value_2, value_1, result);
    } else if (sign_2) {
        ex_code = s21_sub(value_1, value_2, result);
    }
//    s21_set_scale(result, dif_scale);
    if (ex_code) {
        if (s21_get_sign(*result)) ex_code = 2;
        s21_dec_zero(result);
    }

    return ex_code;
}

// 5.(3) + 5.(3) ??? (28 scales)
