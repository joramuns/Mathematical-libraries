//
//  s21_pow.c
//  s21 Math.h
//
//  Created by Joramun Sasin on 6/7/22.
//

#include "s21_math.h"
#include <math.h>

int errcheck(double base, double exp, long double *result) {
    int ex_code = 0;
    int b_is_nan = is_nan(base);
    int b_is_fin = is_fin(base);
    int e_is_nan = is_nan(exp);
    int e_is_fin = is_fin(exp);
    int e_lim = s21_fabs(exp - s21_floor(exp)) <= TOLERANCE;

    /*                  0, exp: (negative odd integer)                      */
    if (b_is_fin && !b_is_nan && base > 0 && base <= TOLERANCE && e_lim &&
        ((int)exp) < 0 && ((int)exp) % 2) {
        *result = s21_INF;
        ex_code = 1;
    }

    /*                  -0, exp: (negative odd integer)                     */
    if (b_is_fin && !b_is_nan && base > 0 && base <= TOLERANCE && e_lim &&
        ((int)exp) < 0 && ((int)exp) % 2) {
        *result = -s21_INF;
        ex_code = 1;
    }

    /*          0, exp: (negative, finite, even integer or non-integer)     */
    if (b_is_fin && !b_is_nan && s21_fabs(base) < TOLERANCE && e_is_fin &&
        ((e_lim && !(((int)exp) % 2)) || !e_lim)) {
        if (base == 0) {
            if (exp == 0) {
                *result = 1;
            } else if (exp > 0) {
                *result = 0;
            } else {
                *result = s21_INF;
            }
        }
        ex_code = 1;
    }

    /*                                  0, -inf                             */
    if (b_is_fin && !b_is_nan && s21_fabs(base) < TOLERANCE && !e_is_nan &&
        !e_is_fin && exp < 0) {
        *result = s21_INF;
        ex_code = 1;
    }

    /*                      0, exp: (positive odd integer)                  */
    if (b_is_fin && !b_is_nan && base > 0 && base <= TOLERANCE && e_lim &&
        ((int)exp) % 2) {
        *result = +0;
        ex_code = 1;
    }

    /*                      -0, exp: (positive odd integer)                 */
    if (b_is_fin && !b_is_nan && base < 0 && base >= -TOLERANCE && e_lim &&
        ((int)exp) % 2) {
        *result = -0;
        ex_code = 1;
    }

    /*                      -0, exp: (positive odd integer)                 */
    if (b_is_fin && !b_is_nan && base < 0 && base >= -TOLERANCE && e_lim &&
        ((int)exp) % 2) {
        *result = -0;
        ex_code = 1;
    }

    /*                  0, exp (positive non-integer or even)               */
    if (exp > 0 && b_is_fin && !b_is_nan && s21_fabs(base) < TOLERANCE &&
        ((!e_lim && s21_fabs(exp) > TOLERANCE) ||
         (e_lim && !(((int)exp) % 2)))) {
        *result = +0;
        ex_code = 1;
    }

    /*                              -1, inf                                 */
    if (b_is_fin && !b_is_nan && s21_fabs(base + 1) < TOLERANCE &&
        !e_is_fin && !e_is_nan) {
        *result = 1;
        ex_code = 1;
    }

    /*                              +1, exp                                 */
    if (b_is_fin && !b_is_nan && s21_fabs(base - 1) < TOLERANCE) {
        *result = 1;
        ex_code = 1;
    }

    /*                              base, 0                                 */
    if (s21_fabs(exp) < TOLERANCE) {
        *result = 1;
        ex_code = 1;
    }

    /*  base, exp (base: noninf and negative, exp: finite, non-integer)     */
    if (!ex_code && b_is_fin && base < -TOLERANCE && e_is_fin && !e_lim) {
        *result = s21_NAN;
        ex_code = 1;
    }

    /*                          base, inf: |base|<1                         */
    if (!ex_code && s21_fabs(base) - 1 < TOLERANCE && !e_is_nan && !e_is_fin && exp < 0) {
        *result = s21_INF;
        ex_code = 1;
    }

    /*                          base, -inf: |base|>1                        */
    if (!ex_code && s21_fabs(base) - 1 > TOLERANCE && !e_is_nan && !e_is_fin && exp < 0) {
        *result = +0;
        ex_code = 1;
    }

    /*                          base, inf: |base|<1                         */
    if (!ex_code && s21_fabs(base) - 1 < TOLERANCE && !e_is_nan && !e_is_fin && exp > 0) {
        *result = +0;
        ex_code = 1;
    }

    /*                          base, inf: |base|>1                         */
    if (!ex_code && s21_fabs(base) - 1 > TOLERANCE && !e_is_nan && !e_is_fin && exp > 0) {
        *result = s21_INF;
        ex_code = 1;
    }

    /*                  -inf, exp: exp negative odd integer                 */
    if (!b_is_nan && !b_is_fin && base < 0 && e_lim && exp < 0 &&
        ((int)exp) % 2 && !ex_code) {
        *result = -0;
        ex_code = 1;
    }

    /*                         -inf, exp: exp negative                      */
    if (!b_is_nan && !b_is_fin && base < 0 &&
        ((!e_lim && exp < 0) || (e_lim && exp < 0 && !(((int)exp) % 2)))) {
        *result = +0;
        ex_code = 1;
    }

    /*                       -inf, exp: exp odd integer                     */
    if (!b_is_nan && !b_is_fin && base < 0 &&
        (e_lim && exp > 0 && ((int)exp) & 1)) {
        *result = -s21_INF;
        ex_code = 1;
    }

    /*                        -inf, exp: exp positive                       */
    if (!b_is_nan && !b_is_fin && base < 0 &&
        ((!e_lim && exp > 0) || (e_lim && exp > 0 && !(((int)exp) % 2)))) {
        *result = +s21_INF;
        ex_code = 1;
    }

    /*                         inf, exp: negative exp                       */
    if (!b_is_nan && !b_is_fin && base > 0 && exp < -TOLERANCE) {
        *result = +0;
        ex_code = 1;
    }

    /*                         inf, exp: positive exp                       */
    if (!b_is_nan && !b_is_fin && base > 0 && exp > TOLERANCE) {
        *result = +s21_INF;
        ex_code = 1;
    }
    /*                               nan-alarm!                             */
    if ((b_is_nan && exp) || (base != 1 && e_is_nan)) {
        *result = s21_NAN;
        ex_code = 1;
    }

    return ex_code;
}

long double s21_pow(double base, double exp) {
    long double result = 0;

    if (!errcheck(base, exp, &result)) {
        if (isint(exp)) {
            result = s21_pow_int(base, exp);
        } else {
            result = s21_pow_float(base, exp);
        }
    }

    return result;
}

int isint(double x) {
    long long int check = x;

    return (x == check) ? 1 : 0;
}

int isodd(double x) {
    return (long long int)x % 2 ? 1 : 0;
}

long double s21_pow_int(double base, double exp) {
    long double result = 1;
    if (exp > 0) {
        while (exp-- >= 1) {
            result *= base;
        }
    } else {
        while (exp++ <= -1) {
            result /= base;
        }
    }

    return result;
}

long double s21_pow_float(double base, double exp) {
    long double result = s21_exp(exp * s21_log(s21_fabs(base)));
    if (!is_fin(result)) {
        result = DBL_MAX;
    }
    if (base < 0 && !isodd(exp)) {
        result = (exp > 0) ? -result : s21_NAN;
    }

    return result;
}
