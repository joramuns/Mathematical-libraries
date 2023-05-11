//
//  asin.c
//  debug
//
//  Created by Joramun Sasin on 6/10/22.
//

#include "s21_math.h"
#include <math.h>

long double s21_asin(double x) {
    long double result = 0;
    if (s21_fabs(x) < 1) {
        if (s21_fabs(x) == (double)(s21_SQRT2 / 2)) {
            result = 0.7853981634;
            if (x < 0) {
                result = -result;
            }
        } else {
            result = s21_atan(x / (s21_sqrt(1 - x * x)));
        }
    } else if (s21_fabs(x) == 1) {
            result = 1.570796;
        if (x < 0) {
            result = -result;
        }
    } else {
        result = s21_NAN;
    }

    return result;
}
