//
//  s21_sqrt.c
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/8/22.
//

#include "s21_math.h"

long double s21_sqrt(double x) {
    long double x1 = (x == 0) ? 0 : s21_NAN;

    if (x == s21_INF) {
        x1 = s21_INF;
    } else if (x > 0) {
        long double x0 = 1.0;
        for (int i = 0; i < 90; i++) {
            x1 = x0 - (s21_function(x0, x) / s21_derivative(x0));
            if (s21_fabs((double)(x1 - x0)) <= TOLERANCE) {
                break;
            }
            x0 = x1;
        }
    }
    return x1;
}

long double s21_function(long double x0, double x) {
    return x0 * x0 - x;
}

long double s21_derivative(long double x0) {
    return 2 * x0;
}
