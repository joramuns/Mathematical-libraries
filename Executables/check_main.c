//
//  check_main.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/17/22.
//

#include "../Tests/check_matrix.h"

int main() {
    srand((unsigned)time(0));
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

    SRunner *sr = srunner_create(suites_matrix[0]);
    srunner_set_fork_status(sr, CK_NOFORK);

    for (size_t i = 1; i < 9; i++)
        srunner_add_suite(sr, suites_matrix[i]);

    srunner_run_all(sr, CK_NORMAL);
    int nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
