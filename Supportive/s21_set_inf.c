//
//  s21_set_inf.c
//  Decimal
//

#include "../s21_decimal.h"

void s21_set_inf(s21_decimal *result) {
    for (int b = 0; b < 3; b++) {
        result->bits[b] = UINT_MAX;
    }
}
