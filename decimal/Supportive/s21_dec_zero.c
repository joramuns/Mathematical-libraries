//
//  s21_dec_zero.c
//  Decimal
//

#include "../s21_decimal.h"

void s21_dec_zero(s21_decimal *decimal) {
    for (int i = 0; i < 4; i++) {
        decimal->bits[i] = 0;
    }
}
