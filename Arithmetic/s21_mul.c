//
//  s21_mul.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
//    s21_decimal zero, temp;
//    s21_dec_zero(&zero);
//    int ex_code = 0;//, scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
//    int dif_scale = scale_1 + scale_2;
//    if (dif_scale > 28) {
//        dif_scale -= 28;
//        s21_div_ten(&value_1, dif_scale);
//        s21_div_ten(&value_2, dif_scale);
//    }
//    while (s21_is_not_equal(value_2, zero) && !ex_code) {
//        if (s21_get_bit_long(value_2, 0)) {
//            s21_dec_copy(*result, &temp);
//            s21_dec_zero(result);
//            ex_code = s21_add(temp, value_1, result);
//        }
//        if (s21_last_non_zero(value_1) < 95) {
//            s21_left_shift_bit(&value_1, 1);
//            s21_right_shift_bit(&value_2, 1);
//        } else {
//            ex_code = 1;
//            s21_set_inf(result);
//        }
//    }
//
//    return ex_code;
//}
    s21_decimal_extra zero, temp, value_1_extra, value_2_extra, result_extra;
    s21_dec_zero_extra(&zero);
    s21_dec_zero_extra(&result_extra);
    s21_dec_to_exdec(value_1, &value_1_extra);
    s21_dec_to_exdec(value_2, &value_2_extra);

    int ex_code = 0;
    while (!s21_is_greater_extra(value_2_extra, zero) && !ex_code) {
        if (s21_get_bit_long_extra(value_2_extra, 0)) {
            s21_dec_copy_extra(result_extra, &temp);
            s21_dec_zero_extra(&result_extra);
            ex_code = s21_add_extra(temp, value_1_extra, &result_extra);
        }
            s21_left_shift_bit_extra(&value_1_extra, 1);
            s21_right_shift_bit_extra(&value_2_extra, 1);
    }
    printf("=============\n");
    s21_print_decimal_extra(result_extra);
    printf("=============\n");

    return ex_code;
}
