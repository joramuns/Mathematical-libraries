//
//  s21_ceil.c
//  debug
//
//  Created by Joramun Sasin on 6/13/22.
//

#include "s21_math.h"

long double s21_ceil(double x) {
    long double res = s21_fabs(x);

    if (res == s21_INF || res == 0) {
        res = x;
    } else if (res == DBL_MAX) {
        res = x;
    } else if (res > 0) {
        res = s21_fabs((long long)x);
        if (res != s21_fabs(x) && (res - s21_fabs(x)) < 1) {
            if (x > 0) {
                res++;
            } else {
                res = -res;
            }
        } else {
            res = x;
        }
    } else {
        res = s21_NAN;
    }

    return res;
}
