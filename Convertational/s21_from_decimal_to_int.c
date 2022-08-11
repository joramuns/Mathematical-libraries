//
//  s21_from_decimal_to_int.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int ex_code = 0;

    int scale = s21_get_scale(src);
    while (scale > 0) {
        s21_div_ten(&src);
        scale--;
    }

    s21_decimal min_int = {{2147483648, 0, 0, 2147483648}};

    if (src.bits[2] != 0 \
        || src.bits[1] != 0 \
        || (s21_get_bit(src.bits[0], 31) == 1 && s21_is_not_equal(src, min_int))) {
        ex_code = 1;
    }

    if (ex_code == 0) {
        *dst = (int)src.bits[0];
        if (s21_get_sign(src)) {
            *dst = -*dst;
        }
    }
    return ex_code;
}
