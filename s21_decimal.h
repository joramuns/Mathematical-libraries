//
//  s21_decimal.h
//  Decimal
//


#ifndef s21_decimal_h
#define s21_decimal_h
#define LOWBIT bits[0]
#define MEDBIT bits[1]
#define HIGHBIT bits[2]
#define BITSIZE 32

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int bits[4];
} s21_decimal;

/*                          Supportive operations                               */
int     s21_get_bit(int block, int num_bit);
int     s21_get_bit_long(s21_decimal decimal, int bit_index);
char*   s21_get_block(int block);
void    s21_print_decimal(s21_decimal number);
void    s21_print_dec_long(s21_decimal number);
int     s21_get_sign(s21_decimal decimal);
int     s21_get_scale(s21_decimal decimal);
void    s21_set_bit(s21_decimal *decimal, int bit_index);
void    s21_set_Sign(s21_decimal *src);
int     s21_shift_bit(s21_decimal *decimal, int step);

/*                      Simple arithmetic operations                            */
/* Return codes:                                                                */
/* 0 - OK                                                                       */
/* 1 - positive infinity                                                        */
/* 2 - negative infinity                                                        */
/* 3 - division by zero                                                         */
    /* Sum +                                                                    */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
    /* Subtraction -                                                            */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
    /* Multiplication *                                                         */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
    /* Division /                                                               */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
    /* Modulo %                                                                 */
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*                        Comparative operations                                */
/* Return codes:                                                                */
/* 0 - True                                                                     */
/* 1 - False                                                                    */
/* <                                                                            */
int s21_is_less(s21_decimal, s21_decimal);
/* =<                                                                           */
int s21_is_less_or_equal(s21_decimal, s21_decimal);
/* >                                                                            */
int s21_is_greater(s21_decimal, s21_decimal);
/* =>                                                                           */
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
/* ==                                                                           */
int s21_is_equal(s21_decimal, s21_decimal);
/* !=                                                                           */
int s21_is_not_equal(s21_decimal, s21_decimal);

/*                      Convertational operations                               */
/* Return codes:                                                                */
/* 0 - OK                                                                       */
/* 1 - mistake                                                                  */
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/*                          Other operations                                    */
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif /* s21_decimal_h */