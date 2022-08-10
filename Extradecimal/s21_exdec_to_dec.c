//
//  s21_exdec_to_dec.c
//  Decimal
//
//  Created by Joramun Sasin on 7/15/22.
//

#include "s21_decimal_extra.h"

int s21_exdec_to_dec(s21_decimal_extra src, s21_decimal *dest) {
    int ex_code = 0;
    s21_decimal_extra temp = INITDECEXTRA;
    s21_dec_copy_extra(src, &temp);

    if (src.bits[DECIMSIZE - 1] || src.bits[DECIMSIZE] || src.bits[DECIMSIZE + 1]) {
        s21_div_ten_extra(&src, 1);
        while (src.bits[DECIMSIZE - 1] || src.bits[DECIMSIZE] || src.bits[DECIMSIZE + 1]) {
            s21_div_ten_extra(&src, 1);
            s21_div_ten_extra(&temp, 1);
            ex_code++;
        }
        s21_bank_rounding_extra(&temp);
        ex_code++;
    }
    for (int i = 0; i < DECIMSIZE - 1; i++) {
        dest->bits[i] = temp.bits[i];
    }

    return ex_code;
}
