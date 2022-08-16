//
//  s21_compare_matrix_sizes.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int s21_compare_matrix_sizes(matrix_t A, matrix_t B) {
    int ex_code = s21_check_matrix(A);

    if (ex_code == OK) ex_code = s21_check_matrix(B);
    if (ex_code == OK) {
        if ((A.rows != B.rows || A.columns != B.columns)) ex_code = C_ERROR;
    }

    return ex_code;
}
