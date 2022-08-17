//
//  check_matrix.h
//  s21_matrix
//
//  Created by Joramun Sasin on 8/17/22.
//

#ifndef SRC_TESTS_CHECK_MATRIX_H_
#define SRC_TESTS_CHECK_MATRIX_H_
#include "../s21_matrix.h"
#include <check.h>

Suite *eq_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *sub_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *mult_matrix_suite(void);
Suite *transpose_matrix_suite(void);
Suite *complements_matrix_suite(void);
Suite *determinant_matrix_suite(void);
Suite *inverse_matrix_suite(void);


#endif  // SRC_TESTS_CHECK_MATRIX_H_
