//
//  check_mult_number.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/17/22.
//

#include "check_matrix.h"

Suite *mult_number_suite(void) {
    Suite *s = suite_create("");
    TCase *tc = tcase_create("");

    tcase_add_test(tc, one);

    suite_add_tcase(s, tc);

    return s;
}

