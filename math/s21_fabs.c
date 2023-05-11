//
//  s21_fabs.c
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/7/22.
//

#include "s21_math.h"

long double s21_fabs(double x) {
    return (x > 0) ? x : -x;
}
