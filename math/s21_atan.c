//
//  atan.c
//  debug
//
//  Created by Joramun Sasin on 6/10/22.
//

#include "s21_math.h"

long double s21_atan(double x) {
    long double result = 0.0;

    if (s21_fabs(x) == s21_INF) {
        result = s21_PI / 2;
        if (x < 0) {
            result = -result;
        }
    } else if (s21_fabs(x) == 1) {
        result = 0.7853981634;
        if (x < 0) {
            result = -result;
        }
    } else if (s21_fabs(x) < 1) {
        for (int i = 0; i < 500; i++) {
            result += s21_pow(-1, i) * s21_pow(x, (1 + (2 * i))) / (1 + (2 * i));
        }
    } else {
        for (int i = 0; i < 500; i++) {
            result += s21_pow(-1, i) * s21_pow(x, (-1 - (2 * i))) / (1 + (2 * i));
        }
        result = (s21_PI * s21_fabs(x)) / (2 * x) - result;
    }

    return result;
}
