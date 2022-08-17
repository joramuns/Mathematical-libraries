//
//  check_main.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/17/22.
//

#include "../Tests/check_matrix.h"

int main() {
    Suite *suites_matrix[] = {
        eq_matrix_suite(),
        sum_matrix_suite(),
        sub_matrix_suite(),
        mult_number_suite(),
        mult_matrix_suite(),
        transpose_matrix_suite(),
        complements_matrix_suite(),
        determinant_matrix_suite(),
        inverse_matrix_suite(),
    };
}
