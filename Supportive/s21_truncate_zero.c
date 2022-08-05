//
//  s21_truncate_zero.c
//  Decimal
//
//  Created by Joramun Sasin on 8/5/22.
//

#include "../s21_decimal.h"

int s21_truncate_zero(s21_decimal *value) {
    int ex_code = 0, scale = s21_get_scale(*value);

    if (scale > 0) {
        s21_decimal temp;
        s21_dec_copy(*value, &temp);
        s21_div_ten(&temp);
        if (s21_is_equal(*value, temp)) {
            s21_div_ten(value);
            s21_set_scale(value, scale - 1);
        } else {
            ex_code = 1;
        }
    } else {
        ex_code = 1;
    }

    return ex_code;
}
