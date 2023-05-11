//
//  s21_div.c
//  Decimal
//

#include "../s21_decimal.h"

s21_decimal_extra s21_div_exdec(s21_decimal_extra value_1_extra, s21_decimal_extra value_2_extra) {
    s21_decimal_extra   remainder = INITDECEXTRA, \
    one = INITDECEXTRA, \
    res_dec = INITDECEXTRA, \
    res_extra = INITDECEXTRA;
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
            remainder = s21_sub_bit_extra(res_dec, value_2_extra);
            s21_dec_zero_extra(&one);
            one.bits[0] = 1;
            res_extra = s21_dec_or(res_extra, one);
        }
    }
    return res_extra;
}

int s21_div_get_no_dot(const s21_decimal value_1, const s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    s21_decimal_extra   value_1_extra = INITDECEXTRA, \
                        value_2_extra = INITDECEXTRA;
    s21_dec_to_exdec(value_1, &value_1_extra);
    s21_dec_to_exdec(value_2, &value_2_extra);
    s21_mul_ten_extra(&value_1_extra, 56);
    s21_decimal_extra res_extra = s21_div_exdec(value_1_extra, value_2_extra);
    s21_exdec_to_dec(res_extra, result);
    // Check check check 79... - 08...
    s21_decimal_extra check_this_shit = INITDECEXTRA;
    s21_dec_to_exdec(*result, &check_this_shit);
    s21_decimal_extra check_this_max = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    s21_mul_ten_extra(&check_this_max, 28);
    if (s21_is_greater_extra(check_this_max, check_this_shit)) ex_code = 1;

    return ex_code;
}

int s21_div_search_dot(s21_decimal value_1, s21_decimal value_2, s21_decimal *result, int bastard) {
    int add_zeros = 0, nums_to_right = 0, scale = 28, ex_code = 0;
    int divide_counter = 0;
    int scale_1 = s21_get_scale(value_1), scale_2 = s21_get_scale(value_2);
    int dif_scale = scale_1 - scale_2;
    s21_decimal_extra   value_1_extra = INITDECEXTRA, \
                        value_2_extra = INITDECEXTRA, \
                        zero_extra = INITDECEXTRA;
    s21_set_scale(result, nums_to_right);
    while (add_zeros < 29) {
        s21_dec_to_exdec(value_1, &value_1_extra);
        s21_dec_to_exdec(value_2, &value_2_extra);
        s21_mul_ten_extra(&value_1_extra, add_zeros);
        s21_decimal_extra search_zero = s21_div_exdec(value_1_extra, value_2_extra);
        if (!s21_is_equal_extra(search_zero, zero_extra)) {
            break;
        }
        add_zeros++;
    }
    while (nums_to_right < 29) {
        s21_dec_to_exdec(value_1, &value_1_extra);
        s21_dec_to_exdec(value_2, &value_2_extra);
        s21_mul_ten_extra(&value_2_extra, nums_to_right + 1);
        s21_decimal_extra search_zero = s21_div_exdec(value_1_extra, value_2_extra);
        if (s21_is_equal_extra(search_zero, zero_extra)) {
            break;
        }
        nums_to_right++;
    }
    while (dif_scale < 0) {
        add_zeros--;
        dif_scale++;
    }
    while (dif_scale > 0) {
        if (nums_to_right > 0) {
            nums_to_right--;
        } else {
//            s21_div_ten(result); -> counter
            divide_counter++;
        }
        dif_scale--;
    }
    while (add_zeros > 0) {
//        s21_div_ten(result); -> counter
        divide_counter++;
        add_zeros--;
    }
    if (add_zeros < 0) {
        nums_to_right -= add_zeros;
    }
    while (divide_counter > 0) {
        if (divide_counter == 1) {
            s21_bank_rounding(result);
        } else {
            s21_div_ten(result);
        }
        divide_counter--;
    }
    scale -= nums_to_right;
    if (bastard) scale--;
    if (scale < 0) {
        ex_code = 1;
    } else {
        s21_set_scale(result, scale);
        s21_truncate_zero(result);
    }

    return ex_code;
}

int s21_div_bit(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int dif_sign = s21_get_sign(value_1) ^ s21_get_sign(value_2);
    int bastard = s21_div_get_no_dot(value_1, value_2, result);
    int ex_code = s21_div_search_dot(value_1, value_2, result, bastard);
    if (dif_sign) {
        s21_set_sign(result);
        if (ex_code) ex_code = 2;
    }

    return ex_code;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ex_code = 0;
    s21_decimal zero = INITDEC;

    if (s21_is_equal_noscale(value_2, zero)) {
        ex_code = 3;
    } else {
        ex_code = s21_div_bit(value_1, value_2, result);
    }

    return ex_code;
}

//  1 / 3
//  1 / 30
//  4 / 3
//  10 / 3
//  11 / 3
//  4 / 2
//  40/2
//  4/20
//  scales 0-1 1-0 1-1 10-10 28-28 28-0 0-28 0-0
