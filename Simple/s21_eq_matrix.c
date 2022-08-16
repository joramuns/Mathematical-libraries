//
//  s21_eq_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int     s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int ex_code = SUCCESS;

    if (s21_compare_matrix_sizes(*A, *B) == OK) {
        for (int i_row = 0; i_row < A->rows; i_row++) {
            for (int i_column = 0; i_column < A->columns; i_column++) {
                double diff = A->matrix[i_row][i_column] - B->matrix[i_row][i_column];
                if (fabs(diff) > TOLERANCE) ex_code = FAILURE;
            }
        }
    } else {
        ex_code = FAILURE;
    }

    return ex_code;
}
