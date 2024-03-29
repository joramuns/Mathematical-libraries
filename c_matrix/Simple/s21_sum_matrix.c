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

    EVERY_ROW
        EVERY_COLUMN
            result->matrix[i_row][i_column] = A->matrix[i_row][i_column] + B->matrix[i_row][i_column];
        }
    }

    return ex_code;
}

int     s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int ex_code = s21_compare_matrix_sizes(*A, *B);

    if (ex_code == OK) {
        ex_code = s21_create_matrix(A->rows, A->columns, result);
        if (ex_code == OK) {
            ex_code = s21_sum_matrix_elements(A, B, result);
        }
    }

    return ex_code;
}
