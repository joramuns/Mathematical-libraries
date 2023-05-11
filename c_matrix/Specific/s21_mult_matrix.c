//
//  s21_mult_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int s21_mult_matrix_go(matrix_t *A, matrix_t *B, matrix_t *result) {
    int ex_code = OK;

    for (int i_row = 0; i_row < result->rows; i_row++) {
        for (int i_column = 0; i_column < result->columns; i_column++) {
            for (int i_b_row = 0; i_b_row < B->rows; i_b_row++) {
                result->matrix[i_row][i_column] += A->matrix[i_row][i_b_row] * B->matrix[i_b_row][i_column];
            }
        }
    }

    return ex_code;
}

int     s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int ex_code = s21_check_matrix(*A);
    if (ex_code == OK) ex_code = s21_check_matrix(*B);

    if (ex_code == OK) {
        if (A->columns == B->rows) {
            ex_code = s21_create_matrix(A->rows, B->columns, result);
            if (ex_code == OK) {
                ex_code = s21_mult_matrix_go(A, B, result);
            }
        } else {
            ex_code = C_ERROR;
        }
    }

    return ex_code;
}
