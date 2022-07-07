//
//  s21_shift_bit.c
//  Decimal
//

#include "../s21_decimal.h"

int s21_left_shift_bit(s21_decimal *decimal, int step) {
    int temp[3] = {0, 0, 0};
    for (; step > 0; step--) {
        for (int i = 0; i < 3; i++) {
            temp[i] = s21_get_bit(decimal->bits[i], 31);
            decimal->bits[i] <<= 1;
            if (i > 0 && temp[i - 1]) {
                s21_set_bit(decimal, i * 32);
            }
        }
    }
    return 0;
}

// Not working yet, just prepared
int s21_right_shift_bit(s21_decimal *decimal, int step) {
    int temp[3] = {0, 0, 0};
    for (; step > 0; step--) {
        for (int i = 2; i >= 0; i--) {
            temp[i] = s21_get_bit(decimal->bits[i], 0);
            decimal->bits[i] >>= 1;
            if (i < 2 && temp[i + 1]) {
                s21_set_bit(decimal, i * 32 + 31);
            }
        }
    }
    return 0;
}
