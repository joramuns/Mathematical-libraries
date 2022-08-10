//
//  s21_decimal_extra.h
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#ifndef s21_decimal_extra_h
#define s21_decimal_extra_h
#include "../s21_decimal_types.h"
#include "../s21_decimal.h"
#include <stdlib.h>
#include <stdio.h>

void    s21_left_shift_bit_extra(s21_decimal_extra *decimal, int step);
void    s21_right_shift_bit_extra(s21_decimal_extra *decimal, int step);
int     s21_get_bit_long_extra(s21_decimal_extra decimal, int bit_index);
int     s21_get_bit_extra(int block, int num_bit);
void    s21_set_bit_extra(s21_decimal_extra *decimal, int bit_index);
void    s21_dec_zero_extra(s21_decimal_extra *decimal);
void    s21_dec_copy_extra(s21_decimal_extra src, s21_decimal_extra *dest);
int     s21_is_greater_extra(s21_decimal_extra value_1, s21_decimal_extra value_2);
int     s21_dec_to_exdec(s21_decimal src, s21_decimal_extra *dest);
int     s21_add_extra(s21_decimal_extra value_1, s21_decimal_extra value_2, s21_decimal_extra *result);
int     s21_last_non_zero_extra(s21_decimal_extra decimal);
void    s21_zero_bit_extra(s21_decimal_extra *decimal, int bit_index);
void    s21_print_decimal_extra(s21_decimal_extra number);
char    *s21_get_block_extra(int block);
int     s21_div_ten_extra(s21_decimal_extra *value, int scale);
int     s21_is_zero_extra(s21_decimal_extra decimal);
int     s21_sub_extra(s21_decimal_extra value_1, s21_decimal_extra value_2, s21_decimal_extra *result);
int     s21_exdec_to_dec(s21_decimal_extra src, s21_decimal *dest);
int     s21_mul_ten_extra(s21_decimal_extra *value, int scale);
int     s21_is_equal_extra(s21_decimal_extra value_1, s21_decimal_extra value_2);
int     s21_is_less_extra(s21_decimal_extra value_1, s21_decimal_extra value_2);
int     s21_sum_bit_extra(int i, s21_decimal_extra *result, int add_bit);
s21_decimal_extra s21_dec_and(s21_decimal_extra value_1, s21_decimal_extra value_2);
s21_decimal_extra s21_dec_or(s21_decimal_extra value_1, s21_decimal_extra value_2);
s21_decimal_extra s21_dec_xor(s21_decimal_extra value_1, s21_decimal_extra value_2);
s21_decimal_extra s21_invert_dec_extra(s21_decimal_extra value);
void    s21_bank_rounding_extra(s21_decimal_extra *value);
s21_decimal_extra s21_sub_bit_extra(s21_decimal_extra value_1_extra, s21_decimal_extra value_2_extra);
int s21_scale_equalize_extra(s21_decimal_extra *value_1, s21_decimal_extra *value_2, int scale_1, int scale_2);

#endif /* s21_decimal_extra_h */
