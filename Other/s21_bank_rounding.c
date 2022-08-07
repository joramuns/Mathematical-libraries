//
//  s21_bank_rounding.c
//  Decimal
//
//  Created by Joramun Sasin on 8/7/22.
//

#include "../s21_decimal.h"

void s21_bank_rounding(s21_decimal *value) {
    s21_decimal temp_dec = *value;

    s21_div_ten(&temp_dec);
    s21_mul_ten(&temp_dec);
    int check_round = value->bits[0] - temp_dec.bits[0];
    s21_div_ten(value);
    if (check_round > 5) {
        value->bits[0]++;
    } else if ((check_round == 5) && (value->bits[0] & 1)) {
            value->bits[0]++;
    }
}




// 123
// 12   // /10 - temp
// 120 //  *10 - temp
// 123 - 120 = 3 - value - temp
// 12 // /10 - value
