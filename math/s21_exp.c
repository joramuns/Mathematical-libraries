//
//  s21_exp.c
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/7/22.
//

#include "s21_math.h"

long double s21_exp(double x) {
    long double res = 0;

    long double mod_x = s21_fabs(x);

    if (x == s21_INF) {
        res = x;
    } else if (x != x) {
        res = s21_NAN;
    } else {
        long double add_val = 1;
        for (double i = 1; add_val > TOLERANCE; i++) {
            res += add_val;
            if (res > DBL_MAX) {
                res = s21_INF;
                break;
            }
            add_val *= mod_x / i;
        }
        if (x < 0) {
            res = 1 / res;
        }
    }

    return res;
}
