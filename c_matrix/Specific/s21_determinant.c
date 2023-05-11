//
//  s21_determinant.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

void s21_determinant_cofactor(matrix_t *A, matrix_t *temp_matrix, \
                              int cross_row, int cross_column, int depth) {
    int i = 0, j = 0;

    for (int i_row = 0; i_row < depth; i_row++) {
        for (int i_col = 0; i_col < depth; i_col++) {
            if (i_row != cross_row && i_col != cross_column) {
                temp_matrix->matrix[i][j++] = A->matrix[i_row][i_col];
                if (j == depth - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double s21_determinant_go(matrix_t *A, int depth) {
    double result_determinant = 0.0;
    if (depth == 1) {
        result_determinant = A->matrix[0][0];
    } else {
        int sign = 1;
        matrix_t temp_matrix = {0};
        s21_create_matrix(A->rows, A->columns, &temp_matrix);
        for (int i_counter = 0; i_counter < depth; i_counter++) {
            s21_determinant_cofactor(A, &temp_matrix, 0, i_counter, depth);
            result_determinant += \
                        sign * A->matrix[0][i_counter] * s21_determinant_go(&temp_matrix, depth - 1);
            sign = -sign;
        }
        s21_remove_matrix(&temp_matrix);
    }

    return result_determinant;
}

int     s21_determinant(matrix_t *A, double *result) {
    int ex_code = s21_check_matrix(*A);

    if (ex_code == OK) {
        if (A->rows == A->columns) {
                *result = s21_determinant_go(A, A->rows);
        } else {
            ex_code = C_ERROR;
        }
    }

    return ex_code;
}
