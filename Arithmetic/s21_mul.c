//
//  s21_mul.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal mul_dec, temp;
    s21_dec_copy(value_2, &mul_dec);
    int len = s21_last_non_zero(value_1);
    int ex_code = 0;

    for (int i = 0; i <= len && !ex_code; i++) {
        if (s21_get_bit_long(value_1, i)) {
            s21_dec_copy(*result, &temp);
            s21_dec_zero(result);
            ex_code = s21_add(temp, mul_dec, result);
        }
        if (!s21_get_bit_long(mul_dec, 95)) {
            s21_left_shift_bit(&mul_dec, 1);
        } else {
            ex_code = 1;
            s21_set_inf(result);
        }
    }

    return ex_code;
}
