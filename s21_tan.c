//
//  s21_tan.c
//  debug
//
//  Created by Joramun Sasin on 6/9/22.
//

#include "s21_math.h"

long double s21_tan(double x) {
    long double res = 0.0;

    if (!is_fin(x) || is_nan(x)) {
        res = s21_NAN;
    } else if (s21_fabs(x) == s21_PI / 2) {
        res = 16331239353195370;
        if (x < 0) {
            res = -res;
        }
    } else {
        res = s21_sin(x) / s21_cos(x);
    }

    return res;
}
