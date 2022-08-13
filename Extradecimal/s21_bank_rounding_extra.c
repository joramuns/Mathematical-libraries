//
//  s21_bank_rounding_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 8/10/22.
//

#include "s21_decimal_extra.h"

int s21_bank_rounding_extra(s21_decimal_extra *value) {
    int ex_code = 0;
    s21_decimal_extra temp_dec = *value;

    s21_div_ten_extra(&temp_dec, 1);
    s21_mul_ten_extra(&temp_dec, 1);
    int check_round = value->bits[0] - temp_dec.bits[0];
    s21_decimal_extra last = INITDECEXTRA;
    s21_sub_extra(*value, temp_dec, &last);
    s21_div_ten_extra(value, 1);
    if ((check_round > 5) || ((check_round == 5) && (value->bits[0] & 1))) {
        if (value->bits[0] != UINT_MAX) {
            value->bits[0]++;
        } else {
            ex_code = 1;
        }
    }

    return ex_code;
}
