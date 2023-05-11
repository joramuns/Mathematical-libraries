//
//  acos.c
//  debug
//
//  Created by Joramun Sasin on 6/10/22.
//

#include "s21_math.h"

long double s21_acos(double x) {
    long double result = s21_NAN;

    if (s21_fabs(x) == 0) {
        result = 1.5707963;
    } else if (s21_fabs(x) < 1) {
        if (s21_fabs(x) == (double)(s21_SQRT2 / 2)) {
            result = (x > 0) ? 0.7853981633974483 : 2.3561944901923448;
        } else {
            result = s21_atan(s21_sqrt(1 - x * x) / x);
            if (-1 < x && x < 0) {
                result += s21_PI;
            }
        }
    } else if (s21_fabs(x) == 1) {
        result = (x > 0) ? 0 : s21_PI;
    }
    return result;
}
