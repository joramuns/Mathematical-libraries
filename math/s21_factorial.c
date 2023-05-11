//
//  s21_factorial.c
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/8/22.
//

#include "s21_math.h"

long double s21_factorial(int base) {
    long double factorial = (base < 0) ? s21_NAN: 1 * ((base == 0) ? 1 : base);

    while (--base > 0) {
        factorial *= base;
    }
    return factorial;
}
