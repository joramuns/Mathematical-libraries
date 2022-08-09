//
//  s21_is_greater.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
    int ex_code = -1;

    if(s21_last_non_zero(value_1) == -1) s21_zero_bit(&value_1, 127);
    if(s21_last_non_zero(value_2) == -1) s21_zero_bit(&value_2, 127);
    if (s21_get_sign(value_1) != s21_get_sign(value_2)) {
        ex_code = s21_get_sign(value_1) ? 0 : 1;
    }
    
    if (ex_code == -1) {
        ex_code = s21_scale_equalize(&value_1, &value_2) - 1;
    }
    
    for (int i = 95; i >= 0 && ex_code == -1; i--) {
        if (s21_get_bit_long(value_1, i) != s21_get_bit_long(value_2, i)) {
            ex_code = s21_get_sign(value_1) == 0 ? \
            s21_get_bit_long(value_1, i) : !s21_get_bit_long(value_1, i);
        }
    }
    if (ex_code == -1) ex_code = 0;
    return ex_code;
}
