//
//  s21_sum_bit_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 8/7/22.
//

#include "s21_decimal_extra.h"

int s21_sum_bit_extra(int i, s21_decimal_extra *result, int add_bit) {
    int ex_code = 0;
    int res_bit = s21_get_bit_long_extra(*result, i);

    if (add_bit ^ res_bit) {
        s21_set_bit_extra(result, i);
    } else if (add_bit & res_bit) {
        s21_zero_bit_extra(result, i);
        if ((i + 1) < (EXTRALASTBIT + 1)) {
            s21_set_bit_extra(result, i + 1);
        } else {
            ex_code = 1;
        }
    }
    return ex_code;
}
