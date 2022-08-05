//
//  s21_div_ten.c
//  Decimal
//
// MODULO!!! no sign

#include "../s21_decimal.h"

void s21_div_ten_aproximation(s21_decimal *value1, s21_decimal *value2, s21_decimal *value3, int i) {
    s21_dec_copy(*value1, value2);
    s21_dec_copy(*value1, value3);
    s21_right_shift_bit(value3, i);
    s21_dec_zero(value1);
    s21_add(*value2, *value3, value1);
}

int s21_div_ten(s21_decimal *value) {
    int ex_code = 0;
    s21_decimal value1, value2, value3, value_r, zero;
    int save_scale = s21_get_scale(*value);
    int save_sign = s21_get_sign(*value);
    s21_dec_zero(&value_r);
    s21_dec_zero(&value1);
    s21_dec_zero(&zero);
/*                       value1 = (value2 >> 1) + (value3 >> 2)                 */
/*                                q = (n >> 1) + (n >> 2)                       */
/*                                 q=n/2+n/4 = 3n/4                             */
    s21_dec_copy(*value, &value2);
    s21_dec_copy(*value, &value3);
    s21_right_shift_bit(&value2, 1);
    s21_right_shift_bit(&value3, 2);
    ex_code = s21_add(value2, value3, &value1);

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
    for (int i = 4; i <= 64; i *= 2) {
        s21_div_ten_aproximation(&value1, &value2, &value3, i);
    }

/*                                      value1 >> 3                             */
/*                                      q = q >> 3                              */
/*                        q = n/8 = (about 0.1n or n/10)                        */
    s21_right_shift_bit(&value1, 3);

/*                          value_r = (value2 << 2) + value3                    */
/*                                      value_r << 1                            */
/*                          value_2 = value - value_r                           */
/*                              r = n - (((q << 2) + q) << 1)                   */
/*                  rounding: r = n-2*(n/10*4+n/10)=n-2*5n/10=n-10n/10          */
    s21_dec_copy(value1, &value2);
    s21_dec_copy(value1, &value3);
    s21_left_shift_bit(&value2, 2);
    ex_code = s21_add(value2, value3, &value_r);
    s21_left_shift_bit(&value_r, 1);
    s21_dec_zero(&value2);
    ex_code = s21_sub(*value, value_r, &value2);

/*                                 return q + (r > 9)                           */
/*                          adjust answer by error term                         */
    s21_dec_zero(&value3);
    value3.bits[0] = 9;
    if (!ex_code) {
        if (s21_is_greater_noscale(value2, value3)) {
            value3.bits[0] = 1;
            s21_dec_zero(value);
            s21_add(value1, value3, value);
        } else if (s21_is_not_equal_noscale(value1, zero)) {
            s21_dec_copy(value1, value);
        } else {
            ex_code = 1;
        }
    }
    if (save_scale) s21_set_scale(value, --save_scale);
    if (save_sign) s21_set_sign(value);

//    if (--scale && !ex_code) {
//        s21_div_ten(value, scale);
//    }
    return ex_code;
}
