//
//  s21_mul.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal zero, temp;
    s21_dec_zero(&zero);
    int ex_code = 0;//, scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
//    int dif_scale = scale_1 + scale_2;
//    if (dif_scale > 28) {
//        dif_scale -= 28;
//        s21_div_ten(&value_1, dif_scale);
//        s21_div_ten(&value_2, dif_scale);
//    }
    while (s21_is_not_equal(value_2, zero) && !ex_code) {
        if (s21_get_bit_long(value_2, 0)) {
            s21_dec_copy(*result, &temp);
            s21_dec_zero(result);
            ex_code = s21_add(temp, value_1, result);
        }
        if (s21_last_non_zero(value_1) < 95) {
            s21_left_shift_bit(&value_1, 1);
            s21_right_shift_bit(&value_2, 1);
        } else {
            ex_code = 1;
            s21_set_inf(result);
        }
    }

    return ex_code;
}
