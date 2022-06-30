//
//  s21_sum_bit.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_sum_bit(int i, s21_decimal *result, int add_bit) {
    int ex_code = 0;
    int res_bit = s21_get_bit_long(*result, i);

    if (add_bit ^ res_bit) {
        s21_set_bit(result, i);
    } else if (add_bit & res_bit) {
        s21_zero_bit(result, i);
        if ((i + 1) < 96) {
            s21_set_bit(result, i + 1);
        } else {
            ex_code = 1;
            s21_set_inf(result);
        }
    }
    return ex_code;
}
