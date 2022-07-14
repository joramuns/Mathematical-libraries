//
//  s21_decimal_extra.h
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#ifndef s21_decimal_extra_h
#define s21_decimal_extra_h

typedef struct {
    unsigned int bits[6];
} s21_decimal_extra;

void    s21_left_shift_bit_extra(s21_decimal_extra *decimal, int step);
void    s21_right_shift_bit_extra(s21_decimal_extra *decimal, int step);
int     s21_get_bit_long_extra(s21_decimal_extra decimal, int bit_index);
int     s21_get_bit_extra(int block, int num_bit);
void    s21_set_bit_extra(s21_decimal_extra *decimal, int bit_index);

#endif /* s21_decimal_extra_h */
