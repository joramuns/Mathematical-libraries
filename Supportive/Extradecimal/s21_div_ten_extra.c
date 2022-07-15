//
//  s21_div_ten_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 7/15/22.
//

#include "s21_decimal_extra.h"

void s21_div_ten_aprox_extra(s21_decimal_extra *value1, s21_decimal_extra *value2, s21_decimal_extra *value3, int i) {
    s21_dec_copy_extra(*value1, value2);
    s21_dec_copy_extra(*value1, value3);
    s21_right_shift_bit_extra(value3, i);
    s21_dec_zero_extra(value1);
    s21_add_extra(*value2, *value3, value1);
}

int s21_div_ten_extra(s21_decimal_extra *value, int scale) {
    int ex_code = 0;
    s21_decimal_extra value1, value2, value3, value_r;
    s21_dec_zero_extra(&value_r);
    s21_dec_zero_extra(&value1);
/*                       value1 = (value2 >> 1) + (value3 >> 2)                 */
/*                                q = (n >> 1) + (n >> 2)                       */
/*                                 q=n/2+n/4 = 3n/4                             */
    s21_dec_copy_extra(*value, &value2);
    s21_dec_copy_extra(*value, &value3);
    s21_right_shift_bit_extra(&value2, 1);
    s21_right_shift_bit_extra(&value3, 2);
    ex_code = s21_add_extra(value2, value3, &value1);

/*                          value1 = value2 + (value3 >> 4)                     */
/*                                  q = q + (q >> 4)                            */
/*                      q = 3n/4+(3n/4)/16 = 3n/4+3n/64 = 51n/64                */
/*                          value1 = value2 + (value3 >> 8)                     */
/*                                  q = q + (q >> 8)                            */
/*           q = 51n/64+(51n/64)/256 = 51n/64 + 51n/16384 = 13107n/16384        */
/*                          value1 = value2 + (value3 >> 16)                    */
/*                                  q = q + (q >> 16)                           */
/*                      q = 13107n/16384+(13107n/16384)/65536 =                 */
/*                13107n/16348+13107n/1073741824 = 858993458n/1073741824        */
/*                             note: q is now roughly 0.8n                      */
/*                          value1 = value2 + (value3 >> 32)                    */
/*                                  q = q + (q >> 32)                           */
/*                          value1 = value2 + (value3 >> 64)                    */
/*                                  q = q + (q >> 64)                           */
    for (int i = 4; i <= 256; i *= 2) {
        s21_div_ten_aprox_extra(&value1, &value2, &value3, i);
    }

/*                                      value1 >> 3                             */
/*                                      q = q >> 3                              */
/*                        q = n/8 = (about 0.1n or n/10)                        */
    s21_right_shift_bit_extra(&value1, 3);

/*                          value_r = (value2 << 2) + value3                    */
/*                                      value_r << 1                            */
/*                          value_2 = value - value_r                           */
/*                              r = n - (((q << 2) + q) << 1)                   */
/*                  rounding: r = n-2*(n/10*4+n/10)=n-2*5n/10=n-10n/10          */
    s21_dec_copy_extra(value1, &value2);
    s21_dec_copy_extra(value1, &value3);
    s21_left_shift_bit_extra(&value2, 2);
    ex_code = s21_add_extra(value2, value3, &value_r);
    s21_left_shift_bit_extra(&value_r, 1);
    s21_dec_zero_extra(&value2);
    ex_code = s21_sub_extra(*value, value_r, &value2);
//
/*                                 return q + (r > 9)                           */
/*                          adjust answer by error term                         */
    s21_dec_zero_extra(&value3);
    value3.bits[0] = 9;
    if (!ex_code) {
        if (!s21_is_greater_extra(value2, value3)) {
            value3.bits[0] = 1;
            s21_dec_zero_extra(value);
            s21_add_extra(value1, value3, value);
        } else if (!s21_is_zero_extra(value1)) {
            s21_dec_copy_extra(value1, value);
        } else {
            ex_code = 1;
        }
    }

    if (--scale && !ex_code) {
        s21_div_ten_extra(value, scale);
    }
    return ex_code;
}
