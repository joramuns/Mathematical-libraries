//
//  s21_scale_equalize.c
//  Decimal
//
//  Created by Alyssa Ivana on 7/16/22.
//

#include "s21_decimal.h"

int s21_scale_equalize(s21_decimal *value_1, s21_decimal *value_2) {
    int ex_code = 0, first_more = 1;
    int scale_1, scale_2;
    scale_1 = s21_get_scale(*value_1);
    scale_2 = s21_get_scale(*value_2);
    
    if (scale_1 != scale_2) {
        s21_decimal temp_dec;
        if (scale_1 > scale_2) {
            temp_dec = *value_2;
        } else {
            temp_dec = *value_1;
            int temp_scale = scale_1;
            scale_1 = scale_2;
            scale_2 = temp_scale;
            first_more = 0;
        }
        while (scale_1 != scale_2 && !ex_code) {
            ex_code = s21_mul_ten(&temp_dec);
            scale_2++;
        }
        if (!ex_code) {
            s21_dec_copy(temp_dec, (first_more) ? value_2 : value_1);
        }
            
        if (ex_code) {
            ex_code = 0;
            scale_2 = s21_get_scale(*value_2);
            if (scale_1 > scale_2) {
                temp_dec = *value_1;
            } else {
                temp_dec = *value_2;
                int temp_scale = scale_1;
                scale_1 = scale_2;
                scale_2 = temp_scale;
                first_more = 0;
            }
            while (scale_1 != scale_2 && !ex_code) {
                ex_code = s21_div_ten(&temp_dec);
                scale_1 --;
            }
            if (!ex_code) {
                s21_dec_copy(temp_dec, (first_more) ? value_1 : value_2);
            }
        }
    }
    return ex_code;
}


