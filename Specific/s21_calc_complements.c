//
//  s21_calc_complements.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int     s21_complements_go(matrix_t *A, matrix_t *result) {
    int ex_code = OK;

    return ex_code;
}

int     s21_calc_complements(matrix_t *A, matrix_t *result) {
    int ex_code = OK;

    if (A->rows == A->columns) {
        ex_code = s21_create_matrix(A->rows, A->columns, result);
        if (ex_code == OK) ex_code = s21_complements_go(A, result);
    } else {
        ex_code = C_ERROR;
    }

    return ex_code;
}
