//
//  s21_math.h
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/7/22.
//

#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stdio.h>
#include <limits.h>
#include <float.h>
#define TOLERANCE 1e-14
#define s21_EXP 2.7182818284590452
#define s21_NAN (__builtin_nanf(""))
#define s21_INF (__builtin_inff())
#define s21_PI 3.14159265358979323
#define s21_PI_2 1.57079632679489661
#define s21_SQRT2 1.41421356237309504880
#define is_nan(x) __builtin_isnan(x)
#define is_fin(x) __builtin_isfinite(x)
#define is_inf(x) __builtin_isinf(x)

int         s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
/*      Additional to pow       */
int         isint(double x);
int         isodd(double x);
long double s21_pow_int(double base, double exp);
long double s21_pow_float(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
/*      Additional to sqrt      */
long double s21_function(long double x0, double x);
long double s21_derivative(long double x0);
/*                              */
long double s21_tan(double x);

long double s21_factorial(int base);

#endif  // SRC_S21_MATH_H_
