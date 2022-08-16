//
//  s21_sum_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//
//  Double overflow?

#include "../s21_matrix.h"

int s21_sum_matrix_elements(matrix_t *A, matrix_t *B, matrix_t *result) {
    int ex_code = OK;

    for (int i_row = 0; i_row < A->rows; i_row++) {
        for (int i_column = 0; i_column < A->columns; i_column++) {
            result->matrix[i_row][i_column] = A->matrix[i_row][i_column] + B->matrix[i_row][i_column];
        }
    }

    return ex_code;
}

int     s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int ex_code = OK;

    if (s21_compare_matrix_sizes(*A, *B) == OK) {
        if (!result->matrix || !result->matrix[0]) {
            s21_create_matrix(A->rows, A->columns, result);
        }
        if (s21_compare_matrix_sizes(*A, *result) == OK) {
            ex_code = s21_sum_matrix_elements(A, B, result);
        } else {
            ex_code = M_ERROR;
        }
    } else {
        ex_code = C_ERROR;
    }

    return ex_code;
}
