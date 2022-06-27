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
    int bits[4];
} s21_decimal;

/*                          Supportive operations                               */
int s21_get_bit(int block, int num_bit);
char *s21_get_block(int block);
void s21_print_decimal(s21_decimal number);

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
