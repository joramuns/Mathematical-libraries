//
//  s21_bank_rounding.c
//  Decimal
//
//  Created by Joramun Sasin on 8/7/22.
//

#include "../s21_decimal.h"

int s21_bank_rounding(s21_decimal *value) {
    int ex_code = 0;
    s21_decimal temp_dec = *value;
    int sign = s21_get_sign(*value);
    if (sign) s21_zero_bit(value, 127);

    s21_div_ten(&temp_dec);
    s21_mul_ten(&temp_dec);
    int check_round = value->bits[0] - temp_dec.bits[0];
    s21_div_ten(value);
    if ((check_round > 5) || ((check_round == 5) && (value->bits[0] & 1))) {
        if (value->bits[0] != UINT_MAX || value->bits[1] != UINT_MAX || value->bits[2] != UINT_MAX) {
            s21_decimal one = INITDECONE;
            s21_add(*value, one, value);
        } else {
            ex_code = 1;
        }
    }
    if (sign) s21_set_bit(value, 127);

    return ex_code;
}

// 123
// 12   // /10 - temp
// 120 //  *10 - temp
// 123 - 120 = 3 - value - temp
// 12 // /10 - value
