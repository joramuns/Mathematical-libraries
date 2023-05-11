//
//  s21_cos.c
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/9/22.
//

#include "s21_math.h"

long double s21_cos(double x) {
    long double res = 0.0;

    if (s21_fabs(x) == s21_INF) {
        res = s21_NAN;
    } else {
        while ((x > s21_PI || x < - s21_PI)) {
            if (x > s21_PI) {
                x -= 2 * s21_PI;
            } else if (x < - s21_PI) {
                x += 2 * s21_PI;
            }
        }

        for (int i = 0; i < 300; i++) {
            res += (s21_pow(-1, i) * s21_pow(x, (2 * i))) / s21_factorial(2 * i);
        }
    }

    return res;
}
