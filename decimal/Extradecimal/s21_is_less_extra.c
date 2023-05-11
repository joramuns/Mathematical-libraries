//
//  s21_is_less_extra.c
//  Decimal
//
//  Created by Joramun Sasin on 8/4/22.
//

#include "s21_decimal_extra.h"

int s21_is_less_extra(s21_decimal_extra value_1, s21_decimal_extra value_2) {
    int result = !s21_is_greater_extra(value_1, value_2);
    if (s21_is_equal_extra (value_1, value_2)) result = 0;

    return result;
}
