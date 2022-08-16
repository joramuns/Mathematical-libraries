//
//  s21_check_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int s21_check_matrix(matrix_t A) {
    int ex_code = OK;

    if (A.matrix) {
        if (A.columns < 1 || A.rows < 1) {
            ex_code = M_ERROR;
        }
    } else {
        ex_code = M_ERROR;
    }

    return ex_code;
}
