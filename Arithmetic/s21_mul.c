//
//  s21_mul.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0, scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
    int dif_scale = scale_1 + scale_2;
    s21_decimal_extra zero, temp, value_1_extra, value_2_extra, result_extra;
    s21_dec_zero_extra(&zero);
    s21_dec_zero_extra(&result_extra);
    s21_dec_to_exdec(value_1, &value_1_extra);
    s21_dec_to_exdec(value_2, &value_2_extra);

    while (s21_is_greater_extra(value_2_extra, zero) && !ex_code) {
        if (s21_get_bit_long_extra(value_2_extra, 0)) {
            s21_dec_copy_extra(result_extra, &temp);
            s21_dec_zero_extra(&result_extra);
            ex_code = s21_add_extra(temp, value_1_extra, &result_extra);
        }
            s21_left_shift_bit_extra(&value_1_extra, 1);
            s21_right_shift_bit_extra(&value_2_extra, 1);
    }
//    while ((result_extra.bits[3] || result_extra.bits[4] || result_extra.bits[5] \
//           || dif_scale > 28) && dif_scale-- > 0 && !ex_code) {
//        ex_code = s21_div_ten_extra(&result_extra, 1);
//    }
//    convertation issue in convertation function - needs to be tested!
    s21_exdec_to_dec(result_extra, result);
    s21_set_scale(result, dif_scale);

    return ex_code;
}
