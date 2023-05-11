//
//  s21_log.c
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/8/22.
//

#include "s21_math.h"

long double s21_log(double x) {
    long double res = 0.0;

    if (x == s21_INF) {
        res = s21_INF;
    } else if (x == -s21_INF) {
        res = s21_NAN;
    } else if (x > 0 && x != 1) {
        int k = 0;
        for (; x >= s21_EXP; x /= s21_EXP, k++) continue;
        for (int i = 0; i < 300; i++) {
            long double exp_res = s21_exp(res);
            if (!is_fin(exp_res)) {
                exp_res = DBL_MAX;
            }
            res += 2 * (x - exp_res) / (x + exp_res);
        }
        res += k;
    } else if (x == 0) {
        res = -s21_INF;
    } else if (x == 1) {
        res = 0;
    } else {
        res = s21_NAN;
    }

    return res;
}
