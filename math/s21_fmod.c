//
//  s21_fmod.c
//  debug
//
//  Created by Joramun Sasin on 6/13/22.
//

#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double res = 0.0;

    if (s21_fabs(y) == 0 || y != y || s21_fabs(x) == s21_INF) {
        res = s21_NAN;
    } else if (s21_fabs(y) == s21_INF) {
        res = x;
    } else if (s21_fabs(y) != 1) {
        res = s21_fabs(x);
        while (res >= s21_fabs(y)) {
            res -= s21_fabs(y);
        }
    }
    if (x < 0) {
        res = -res;
    }

    return res;
}
