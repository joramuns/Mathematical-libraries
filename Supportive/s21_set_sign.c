//
//  s21_set_Sign.c
//  Decimal
//
//  Created by Alyssa Ivana on 6/27/22.
//  Принимает на вход число decimal, устанавливает отрицательный знак, независимо от того, какой знак был до этого

#include "../s21_decimal.h"

void s21_set_sign(s21_decimal *src) {
    src->bits[3] = src->bits[3]|(1 << 31);
}
