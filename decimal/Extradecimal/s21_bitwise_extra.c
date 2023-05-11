//
//  s21_bitwise_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 8/9/22.
//

#include "s21_decimal_extra.h"

s21_decimal_extra s21_dec_and(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    s21_decimal_extra result = INITDECEXTRA;

    for (int i = 0; i < EXTRASIZE; i++) {
        result.bits[i] = value_1.bits[i] & value_2.bits[i];
    }

    return result;
}

s21_decimal_extra s21_dec_or(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    s21_decimal_extra result = INITDECEXTRA;

    for (int i = 0; i < EXTRASIZE; i++) {
        result.bits[i] = value_1.bits[i] | value_2.bits[i];
    }

    return result;
}

s21_decimal_extra s21_dec_xor(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    s21_decimal_extra result = INITDECEXTRA;

    for (int i = 0; i < EXTRASIZE; i++) {
        result.bits[i] = value_1.bits[i] ^ value_2.bits[i];
    }

    return result;
}

s21_decimal_extra s21_invert_dec_extra(s21_decimal_extra value) {
    s21_decimal_extra result = INITDECEXTRA;

    for (int i = 0; i < EXTRASIZE; i++) {
        result.bits[i] = ~value.bits[i];
    }

    return result;
}
